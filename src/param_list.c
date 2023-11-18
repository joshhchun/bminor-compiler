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

/* Function to duplicate a param_list */
struct param_list* param_list_copy(struct param_list* l) {
    if (!l) return 0;
    return param_list_create(strdup(l->ident), type_copy(l->type), param_list_copy(l->next));
}

/* Function to determine if two param lists are the same recursively */
int param_list_same(struct param_list* p1, struct param_list* p2) {
    for (; p1 || p2; p1 = p1->next, p2 = p2->next) {
        if ((!p1 || !p2) || strcmp(p1->ident, p2->ident) || !type_same(p1->type, p2->type)) {
            printf("param list is different\n");
            return 0;
        }
    }
    return 1;
}

/* Function to delete a param struct */
void param_list_delete(struct param_list *p) {
    if (!p) return;
    param_list_delete(p->next);
    type_delete(p->type);
    if (p->ident) free(p->ident);
    free(p);
}
