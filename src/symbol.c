#include "../include/symbol.h"

struct symbol* symbol_create(symbol_t kind, struct type* type, char* ident) {
    struct symbol *s;
    if (!(s = calloc(1, sizeof(struct symbol)))) {
        fprintf(stderr, "ERROR: Could not allocate enough memory for symbol.\n");
        exit(EXIT_FAILURE);
    };
    s->kind = kind;
    s->type = type;
    s->ident = ident;
    return s;
}
