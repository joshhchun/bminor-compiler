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

/* Internal helper to check if two types are same (and subtypes) */
int _type_same(struct type* t1, struct type* t2) {
    struct type *t = t1, *s = t2;
    for (; t || s; t = t->subtype, s = s->subtype) {
        if ((!t || !s) || t->kind != s->kind) return 1;
    }
    return 0;
}

/* Function to check if two types are the same types are same */
int type_same(struct type* t1, struct type* t2) {
    if (t1->kind != t2->kind) return 1;
    if (t1->kind == TYPE_FUNC) {
        if (type_same(t1->subtype, t2->subtype) || param_list_same(t1->params, t2->params))
            return 1;
    } else if (t1->kind == TYPE_ARRAY) {
        return type_same(t1->subtype, t2->subtype);
    }
    return 0;
}

/* Function to duplicate a type recursively */
struct type* type_copy(struct type *t) {
    if (!t) return t;
    return type_create(t->kind, type_create(t->subtype->kind, 0, 0), param_list_copy(t->params));
}

void type_delete(struct type* t) {
    if (!t) return;
    type_delete(t->subtype);
    param_list_delete(t->params);
    free(t);

}
