#include "../include/decl.h"

struct decl* decl_create(char *ident, struct type *type, struct expr *value, struct stmt *code, struct decl *next) {
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


void decl_print(struct decl *d, int indents) {
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
        stmt_print(d->code, indents);
        indent(indents);
    } else {
        fprintf(stdout, ";\n");
    }
    if (d->next) {
        decl_print(d->next, indents);
    }
}
