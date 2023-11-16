#ifndef TYPE_H
#define TYPE_H

#include "param_list.h"
#include "expr.h"

typedef enum {
    TYPE_VOID,
    TYPE_BOOL,
    TYPE_CHAR,
    TYPE_FLOAT,
    TYPE_INT,
    TYPE_STR,
    TYPE_ARRAY,
    TYPE_FUNC,
} type_t;

typedef struct type {
    type_t             kind;
    struct param_list* params;
    struct type*       subtype;
    struct expr*       array_size;
} type;

struct type* type_create(type_t kind, struct type* subtype, struct param_list* params);
struct type* type_copy(struct type *t);
void         type_print(struct type *t);
void         type_delete(struct type* t);
int          type_func_same(struct type* t1, struct type* t2);
int          type_same(struct type* t1, struct type* t2);

#endif
