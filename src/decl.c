#include "../include/decl.h"
extern int ERR_COUNT;

struct decl* decl_create(char* ident, struct type* type, struct expr* value, struct stmt* code, struct decl* next) {
    struct decl* d;
    if (!(d = calloc(1, sizeof(struct decl)))) {
        fprintf(stderr, "ERROR: Could not allocate enough memory for expr_create.\n");
        exit(EXIT_FAILURE);
    }
    d->ident = ident;
    d->type = type;
    d->value = value;
    d->code = code;
    d->next = next;
    return d;
}


void decl_print(struct decl* d, int indents) {
    extern void indent(int indents);
    if (!d) return;
    fprintf(stdout, "%s: ", d->ident);
    type_print(d->type);

    if (d->value){
        fprintf(stdout, " = ");
        expr_print(d->value);
    }

    if (d->code){
        fprintf(stdout, " = ");
        stmt_print(d->code, indents, true);
        indent(indents);
    } else {
        fprintf(stdout, ";");
    }
}

void decl_print_list(struct decl *d, int indents){
    if (!d) return;
    decl_print(d, indents);
    fprintf(stdout, "%s", "\n");
    decl_print_list(d->next, indents);
}


void decl_resolve(struct decl* d) {
    if (!d) return;
    // Create a new symbol
    symbol_t kind = scope_level() > 1 ? SYMBOL_LOCAL : SYMBOL_GLOBAL; 

    // Bind it to the name of the decl in curr scope (top)
    d->symbol = symbol_create(kind, d->type, d->ident);

    // Try to resolve the value
    expr_resolve(d->value);

    // Set if the decl is a function definition
    d->symbol->func_defined = (d->code) ? 1 : 0;

    // Bind the name to the symbol
    scope_bind(d->ident, d->symbol);

    // If decl == func (d->code != null) then create new scope, resolve params, and code
    if (d->symbol->func_defined) {
        scope_enter();
        param_list_resolve(d->type->params);
        stmt_resolve(d->code);
        scope_exit();
    }
    decl_resolve(d->next);
}

/* Internal helper function to typecheck array initializations */
void arr_init_typecheck(struct type* arr_t, struct expr* e) {
    struct type* curr_t = {0};
    // For every dimension, make sure all the type matches the curr subtype
    if (!arr_t) {
        fprintf(stdout, "Type Error: Too many nested arrays\n");
        ERR_COUNT++;
        return;
    }
    for (; e; e = e->right) {
        if (e->left->kind == EXPR_ARRAY_INIT) {
            if (arr_t->kind != TYPE_ARRAY) {
                fprintf(stdout, "Type Error: Cannot assign array to subtype of ");
                type_print(arr_t);
                fprintf(stdout, "\n");
                ERR_COUNT++;
            }
            arr_init_typecheck(arr_t->subtype, e->left->left);
            continue;
        }
        if ((curr_t = expr_typecheck(e->left))->kind != arr_t->kind) {
            fprintf(stdout, "Type Error: Cannot assign ");
            type_print(curr_t);
            fprintf(stdout, " (");
            expr_print(e->left);
            fprintf(stdout, ") to array subtype of ");
            type_print(arr_t);
            fprintf(stdout, "\n");
            ERR_COUNT++;
        }
    }
}

/* Function to check if return types of a function matches the subtype */
void func_typecheck(struct type* t, struct stmt* s, const char* func_name) {
    if (!s) return;
    if (s->kind == STMT_RETURN) {
        if (expr_typecheck(s->expr)->kind != t->kind) {
            // TODO:
            fprintf(stderr, "Type Error: non matching return types");
            ERR_COUNT++;
        }
    }
    // Check every type of block that could exist (returns if null)
    func_typecheck(t, s->body, func_name);
    func_typecheck(t, s->else_body, func_name);
    func_typecheck(t, s->next, func_name);
}


void decl_typecheck(struct decl* d) {
    if (!d) return;
    // Assignment
    if (d->value) {
        switch (d->type->kind) {
        case TYPE_ARRAY:
            // Make sure each element matches the subtype of the array
            arr_init_typecheck(d->type->subtype, d->value->left);
            break;
        default: {
            // All basic types, just check left matches right
            struct type* t = expr_typecheck(d->value);
            if (t->kind != d->type->kind) {
                fprintf(stderr, "Type Error: Assigment of ");
                type_print(t);
                fprintf(stderr, " (");
                expr_print(d->value);
                fprintf(stderr, ") does not match decl of ");
                type_print(d->type);
                fprintf(stderr, " (%s)\n", d->ident);
                ERR_COUNT++;
            }
        }
        }
    }
    
    if (d->code) {
        // Make sure return type(s) match the subtype
        stmt_typecheck(d->code, d->symbol);
    }
    decl_typecheck(d->next);
}
