#include "../include/symbol.h"
int         VAR_SIZE = -8;
const char* VAR_REG = "(%rbp)";

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
           resolve_print("%s resolves to local: %d.\n", s->ident, s->which) ;
           break;
        case SYMBOL_PARAM:
           resolve_print("%s resolves to param: %d.\n", s->ident, s->which) ;
           break;
        case SYMBOL_GLOBAL:
           resolve_print("%s resolves to global: %s.\n", s->ident, s->ident) ;
            break;
        }
}

/* Function to generate the stack address of a symbol */
const char* symbol_codegen(struct symbol *s) {
    // If the symbol scope is global just return the ident
    if (s->kind == SYMBOL_GLOBAL) {
        return s->ident;
    } else {
        char buf[BUFSIZ] = {0};
        int  offset = s->which + 1;
        // If the symbol is local then we have to include the offset of params
        if (s->kind == SYMBOL_LOCAL) offset += param_list_count(s->type->params);
        sprintf(buf, "%d%s", offset * VAR_SIZE, VAR_REG);
        char* sym = strdup(buf);
        if (!sym) {
            fprintf(stdout, "ERROR: Not enough memory to allocate param symbol codegen.\n");
            exit(1);
        }
        return sym;
    }
}
