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
    printf("in decl resolve..\n");
    // Create a new symbol
    symbol_t kind = scope_level() > 1 ? SYMBOL_LOCAL : SYMBOL_GLOBAL; 

    // Bind it to the name of the decl in curr scope (top)
    d->symbol = symbol_create(kind, d->type, d->ident);

    // Try to resolve the value
    expr_resolve(d->value);

    // Try to resolve arr_size if it exists;
    if (d->type->array_size) expr_resolve(d->type->array_size);

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
        fprintf(stdout, "Type Error: Too many nested arrays in initialization\n");
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
            expr_type_print(e->left, curr_t);
            fprintf(stdout, " to array subtype of ");
            type_print(arr_t);
            fprintf(stdout, "\n");
            ERR_COUNT++;
        }
    }
}


/* Internal helper functino to convert a type_t type to an expr_t type */
expr_t expr_type_conv (type_t t) {
    switch (t) {
        case TYPE_BOOL:
            return EXPR_BOOL;
        case TYPE_CHAR:
            return EXPR_CHAR_LITERAL;
        case TYPE_FLOAT:
            return EXPR_FLOAT_LITERAL;
        case TYPE_INT:
            return EXPR_INT_LITERAL;
        case TYPE_STR:
            return EXPR_STRING_LITERAL;
        default:
            fprintf(stderr, "Unreachable.\n");
            return -1;
    }
}

void global_array_typecheck(struct decl *d) {
    struct type* t = d->symbol->type;
    for (; t->subtype; t = t->subtype) {
        if (!t->array_size) {
            fprintf(stdout, "Type Error: Arrays cannot have an empty size (%s)\n", d->ident);
            ERR_COUNT++;
        } else if (t->array_size->kind != EXPR_INT_LITERAL) {
            fprintf(stdout, "Type Error: Global arrays must have a constant integer size, given ");
            struct type* arr_size_type = expr_typecheck(t->array_size);
            expr_type_println(t->array_size, arr_size_type);
            ERR_COUNT++;
        }
    }
    // Make sure each element matches the subtype of the array if it has an initializer
    if (d->value) arr_init_typecheck(d->type->subtype, d->value->left);
}

/* Function to make sure that local array decls have an integer expression sized */
void local_array_typecheck(struct decl* d) {
    struct type* arr_size_type = 0;
    for (struct type* t = d->symbol->type; t->subtype; t = t->subtype) {
        if (!t->array_size) {
            fprintf(stdout, "Type Error: Arrays cannot have an empty size (%s)\n", d->ident);
            ERR_COUNT++;
        }
        else if ((arr_size_type = expr_typecheck(t->array_size))->kind != TYPE_INT) {
            fprintf(stdout, "Type Error: Local arrays must have an integer expression size, given:");
            expr_type_println(t->array_size, arr_size_type);
            ERR_COUNT++;
            free(arr_size_type);
        }
    }
    if (d->value) {
        fprintf(stdout, "Type Error: Local arrays cannot have an initializer list\n");
        ERR_COUNT++;
    }
}

/* Function to make sure that global decls only have constant values */
void global_var_typecheck(struct decl* d) {
    // Make sure the expression is only of the constant type of the ident
    expr_t expr_type = expr_type_conv(d->symbol->type->kind);
    for (struct expr* e = d->value; e; e = e->right) {
        if (e->kind != expr_type) {
            fprintf(stdout, "Type Error: Global variable ");
            type_print(d->symbol->type);
            fprintf(stdout, " (%s) must be assigned a constant expression, given (", d->ident);
            expr_print(d->value);
            fprintf(stdout, ")\n");
            ERR_COUNT++;
        }
    }
}


/* Function to make sure the assignment expression matches the decl types for local vars */
void local_var_typecheck(struct decl* d) {
    struct type* t = expr_typecheck(d->value);
    if (t->kind != d->type->kind) {
        fprintf(stdout, "Type Error: Assigment of ");
        expr_type_print(d->value, t);
        fprintf(stdout, " does not match decl of ");
        type_print(d->type);
        fprintf(stdout, " (%s)\n", d->ident);
        ERR_COUNT++;
    }
    free(t);
}

/* Function to typecheck declarations */
void decl_typecheck(struct decl* d) {
    if (!d) return;

    bool is_global = (d->symbol->kind == SYMBOL_GLOBAL ? 1 : 0);

    switch (d->symbol->type->kind) {
        case TYPE_ARRAY:
            if (is_global) global_array_typecheck(d);
            else           local_array_typecheck(d);
            break;
        case TYPE_FUNC:
            if (d->code)   stmt_typecheck(d->code, d->symbol);
            break;
        default:
            if (d->value) {
                if (is_global) global_var_typecheck(d);
                else           local_var_typecheck(d);
            }
            break;
    }
    decl_typecheck(d->next);
}
