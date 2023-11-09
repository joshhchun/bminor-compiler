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

void symbol_print(struct symbol* s){
    switch (s->kind) {
        case SYMBOL_LOCAL:
           fprintf(stdout, "%s resolves to local: %d.\n", s->ident, s->which) ;
           break;
        case SYMBOL_PARAM:
           fprintf(stdout, "%s resolves to param: %d.\n", s->ident, s->which) ;
           break;
        case SYMBOL_GLOBAL:
           fprintf(stdout, "%s resolves to global: %s.\n", s->ident, s->ident) ;
            break;
        }
}
