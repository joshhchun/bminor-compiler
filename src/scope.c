#include "../include/scope.h"
#include <stdlib.h>

struct symbol_table* sym_t = NULL;
extern int ERR_COUNT;

void create_symbol_table() {
    if (sym_t) return;
    if (!(sym_t = calloc(1, sizeof(struct symbol_table)))) {
        fprintf(stderr, "ERROR: Could not allocate enough memory for symbol table.\n");
        exit(EXIT_FAILURE);
    }
}

struct scope* create_scope() {
    struct scope* s;
    if (!(s = calloc(1, sizeof(struct scope)))) {
        fprintf(stderr, "ERROR: Could not allocate enough memory for a scope.\n");
        exit(EXIT_FAILURE);
    }
    return s;
}

/* Push a new scope (hash table) to the stack */
void scope_enter() { 
    struct scope *s = create_scope();
    s->table = hash_table_create(0, 0);
    s->prev = sym_t->top;
    sym_t->top = s;
    sym_t->level += 1;
}

/* Remove the topmost hash table (scope) from symbol table */
void scope_exit() {
    struct scope* curr_top;
    if (!sym_t || !(curr_top = sym_t->top)) return;
    sym_t->top = curr_top->prev;
    hash_table_delete(curr_top->table);
    free(curr_top);
    sym_t->level -= 1;
}

/* Returns what level of scope we are currently in */
int scope_level() {
    return sym_t->level;
}

int scope_insert(struct symbol* s) {
    // No redeclaration conflicts
    if (hash_table_insert(sym_t->top->table, s->ident, s)) return 0;
    struct symbol* lookup_s = scope_lookup_current(s->ident);

    /* Function prototypes can be repeated unlimited times (and wherever) but func def can only happen once.
     *
     * How to check for func
     * 1. Should be on level 1 (parsing should handle this)
     * 2. symbol->type->kind == TYPE_FUNC
     * 3. lookup_s->type->kind == TYPE_FUNC
     * 4. if lookup_s->func_defined == true, then symbol->func_defined != true
     * 4.1 if that is true, don't overwrite symbol, need to keep func_defined
     * 5. Content of prototype(s) and func def have to be the same (happens in typechecker?)
    */

    /* Not a func redecl, just an error */
    if (s->type->kind != TYPE_FUNC ||
        lookup_s->type->kind != TYPE_FUNC ||
        (lookup_s->func_defined && s->func_defined) ||
        !type_same(s->type, lookup_s->type)
        ) {
        /* TODO: Just keeping prev decl for now, but should exit program here. */
        return 1;
    }

    /* Func redecl, need to be careful */
    // If one of the symbols has a func def then we need to mark that for future func redecls.
    lookup_s->func_defined = lookup_s->func_defined || s->func_defined;
    return 0;
    
}

/* Adds entry to top scope, mapping name to symbol struct */
void scope_bind(const char* name, struct symbol* s) {
    extern int var_count;
    /* Check for redeclarations */
    if (scope_insert(s)) {
        fprintf(stderr, "Resolve Error: Redeclaration of %s.\n", s->ident);
        ERR_COUNT++;
    };
    
    /* Set the which */
    switch (s->kind) {
        case SYMBOL_PARAM:
            s->which = sym_t->top->param_count++;
            break;
        case SYMBOL_LOCAL:
            s->which = var_count++;
            break;
        case SYMBOL_GLOBAL:
            s->which = 0;
            break;
    }
}

/* Searches the symbol table for the first entry that matches ident exactly */
struct symbol* scope_lookup(const char* ident) {
    struct symbol* s = NULL;
    for (struct scope* c = sym_t->top; c; c = c->prev) {
        if ((s = hash_table_lookup(c->table, ident))) break;
    }
    return s;
}

/* Searches top scope for a ident */
struct symbol* scope_lookup_current(const char* ident) {
    return hash_table_lookup(sym_t->top->table, ident);
}
