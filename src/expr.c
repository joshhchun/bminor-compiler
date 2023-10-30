#include "../include/expr.h"

struct expr*  expr_create( expr_t kind, struct expr* left,struct expr* right ) {
    struct expr* e;
    if (!(e = calloc(1, sizeof(struct expr)))) {
        fprintf(stderr, "ERROR: Could not allocate enough memory for expr_create.\n");
        exit(EXIT_FAILURE);
    };
    e->kind = kind;
    e->left = left;
    e->right = right;
    return e;
}
/* Idents */
struct expr* expr_create_ident(const char *n) {
    struct expr* e = expr_create(EXPR_IDENT, 0, 0);
    e->name = n;
    return e;
}
/* Literals */
struct expr* expr_create_integer_literal(int c) {
    struct expr* e = expr_create(EXPR_INT_LITERAL, 0, 0);
    e->int_literal = c;
    return e;
}
struct expr* expr_create_bool_literal(int c) {
    struct expr* e = expr_create(EXPR_BOOL, 0, 0);
    e->bool_literal = c;
    return e;
}
struct expr* expr_create_float_literal(float c) {
    struct expr* e = expr_create(EXPR_FLOAT_LITERAL, 0, 0);
    e->float_literal = c;
    return e;
}
struct expr* expr_create_char_literal(char c) {
    struct expr* e = expr_create(EXPR_CHAR_LITERAL, 0, 0);
    e->char_literal = c;
    return e;
}
struct expr* expr_create_string_literal(const char *str) {
    struct expr* e = expr_create(EXPR_STRING_LITERAL, 0, 0);
    char *dup_string = strdup(str);
    if (!dup_string) {
        fprintf(stderr, "ERROR: Not enough space to allocate string literal.\n");
    }
    e->string_literal = dup_string;
    return e;
}

/*TODO: (Work on recursive case) Array subscripts */
struct expr* expr_create_array_sub(struct expr* ident, struct expr* index) {
    struct expr* e  = expr_create(EXPR_ARRAY_SUB, 0, 0);
    e->left  = ident;
    e->right = index;
    return e;
}

