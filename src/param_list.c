#include "../include/param_list.h"

extern int ERR_COUNT;

param_list* param_list_create(char* ident, struct type* type, struct param_list* next) {
    param_list* p;
    if (!(p = calloc(1, sizeof(param_list)))) {
        fprintf(stderr, "ERROR: Could not allocate enough memory for param_list_create.\n");
        exit(EXIT_FAILURE);
    };
    p->ident = ident;
    p->type = type;
    p->next = next;
    return p;
}

/* Printing param lists */
void param_list_print(struct param_list* l) {
    for (struct param_list* p = l; p; p = p->next) {
        fprintf(stdout, "%s: ", p->ident);
        type_print(p->type);
        if (p->next) fprintf(stdout, ", ");
    }
}

/* Name resolution of param_list */
void param_list_resolve(struct param_list *l) {
    if (!l) return;
    size_t param_count = 0;
    for (struct param_list* p = l; p; p = p->next, param_count++) {
        // Check for duplicate parameters
        if (scope_lookup_current(p->ident)) {
            fprintf(stderr, "Resolve Error: Duplicate param %s.\n", p->ident);
            ERR_COUNT++;
        }
        p->symbol = symbol_create(SYMBOL_PARAM, p->type, p->ident);
        // Bind the param to the current func scope
        scope_bind(p->ident, p->symbol);
    }
}
