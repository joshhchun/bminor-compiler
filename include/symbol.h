
#ifndef SYMBOL_H
#define SYMBOL_H

#include "type.h"
#include <stdbool.h>

typedef enum {
    SYMBOL_LOCAL,
    SYMBOL_PARAM,
    SYMBOL_GLOBAL
} symbol_t;

struct symbol {
    symbol_t     kind;
    struct type* type;
    char*        ident;
    int          which;
    bool         func_defined;
};

struct symbol* symbol_create(symbol_t kind, struct type* type, char* ident);
void           symbol_print(struct symbol* s);

#endif
