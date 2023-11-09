#ifndef SCOPE_H
#define SCOPE_H
struct symbol;

#include "../include/symbol.h"
#include "../include/hash_table.h"

struct scope {
    struct hash_table* table;
    struct scope* prev;
    int local_count;
    int param_count;
};

struct symbol_table {
    struct scope* top;
    int level;
};

int            scope_level();
int            scope_insert(struct symbol* s);
void           create_symbol_table();
void           scope_enter();
void           scope_exit();
void           scope_bind(const char* name, struct symbol* s);

struct scope*  create_scope();
struct symbol* scope_lookup(const char* name);
struct symbol* scope_lookup_current(const char* name);

#endif
