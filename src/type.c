#include "../include/type.h"

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

/* Check if two types are same (and subtypes) */
int type_same(struct type* t1, struct type* t2) {
    struct type *t = t1, *s = t2;
    for (; t || s; t = t->subtype, s = s->subtype) {
        if ((!t || !s) || t->kind != s->kind) return 1;
    }
    return 0;
}

/* Check if two func types are same (including param list) */
int type_func_same(struct type* t1, struct type* t2) {
    // Check if the types and subtypes are same
    if (type_same(t1, t2)) {
        printf("TYPE SAME FAILED - before params\n");
        return 1;
    }
    // Check if param lists are same
    struct param_list *p1 = t1->params, *p2 = t2->params;
    for (; p1 || p2; p1 = p1->next, p2 = p2->next) {
        if ((!p1 || !p2) || strcmp(p1->ident, p2->ident) || type_same(p1->type, p2->type)) return 1;
    }
    return 0;
}
