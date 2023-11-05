#include "../include/type.h"
#include "../include/expr.h"

type* type_create(type_t kind, struct type* subtype, struct param_list* params) {
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

void type_print(struct type* t) {
    if (!t) return;

    char *type_s [] = {"void", "boolean", "char", "float", "integer", "string", "array", "function"};
    fprintf(stdout, "%s", type_s[t->kind - TYPE_VOID]);
    switch(t->kind){
        case TYPE_ARRAY:
            fputs(" [", stdout);
            expr_print(t->array_size);
            fputs("] ", stdout);
            type_print(t->subtype);
            break;
        case TYPE_FUNC:
            fputs(" ", stdout);
            type_print(t->subtype);
            fputs(" (", stdout);
            param_list_print(t->params);
            fputs(")", stdout);
            break;
        default:
            break;
    }
}
