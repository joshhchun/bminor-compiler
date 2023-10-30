#include "../include/type.h"

type* type_create( type_t kind, struct type *subtype, struct param_list *params ) {
    type* t;
    if (!(t = calloc(1, sizeof(type)))) {
        fprintf(stderr, "ERROR: Could not allocate enough memory for expr_create.\n");
        exit(EXIT_FAILURE);
    }
    t->kind = kind;
    t->subtype = subtype;
    t->params = params;
    return t;    
}

