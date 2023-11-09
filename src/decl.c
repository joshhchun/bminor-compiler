#include "../include/decl.h"

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


/* TODO: Can repeat func prototypes but can't repeat assigned functions... */
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
