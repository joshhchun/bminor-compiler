
#ifndef PARAM_LIST_H
#define PARAM_LIST_H

#include "type.h"
#include "scope.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct expr;

typedef struct param_list {
    char*              ident;
    struct type*       type;
    struct symbol*     symbol;
    struct param_list* next;
} param_list;

struct param_list* param_list_create(char* ident, struct type* type, struct param_list* next);
void param_list_print(struct param_list* l);
void param_list_resolve(struct param_list* l);

#endif
