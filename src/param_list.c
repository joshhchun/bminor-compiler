#include "../include/param_list.h"

param_list* param_list_create( char *name, struct type *type, struct param_list *next ) {
    param_list* p;
    if (!(p = calloc(1, sizeof(param_list)))) {
        fprintf(stderr, "ERROR: Could not allocate enough memory for param_list_create.\n");
        exit(EXIT_FAILURE);
    };
    p->name = name;
    p->type = type;
    p->next = next;
    return p;

}
