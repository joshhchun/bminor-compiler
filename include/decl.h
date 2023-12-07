
#ifndef DECL_H
#define DECL_H

#include "type.h"
#include "stmt.h"
#include "expr.h"
#include <stdio.h>

struct decl {
    char*          ident;
    struct type*   type;
    struct expr*   value;
    struct stmt*   code;
    struct symbol* symbol;
    struct decl*   next;
};

int var_count;
char* curr_func_name;

struct decl* decl_create(char* ident, struct type* type, struct expr* value, struct stmt* code, struct decl* next);
void         decl_print(struct decl* d, int indent);
void         decl_print_list(struct decl* d, int indents);
void         decl_resolve(struct decl* d);
void         decl_typecheck(struct decl* d);
void         decl_codegen(struct decl* d);

#endif


