#include "../include/expr.h"


void expr_print_list(struct expr *e, char *delim);

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
    e->ident = n;
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
struct expr* expr_create_char_literal(char* c) {
    struct expr* e = expr_create(EXPR_CHAR_LITERAL, 0, 0);
    char *dup_string = strdup(c);
    if (!dup_string) {
        fprintf(stderr, "ERROR: Not enough space to allocate char literal.\n");
    }
    e->char_literal = dup_string;
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

/* Array subscripts */
struct expr* expr_create_array_sub(struct expr* ident, struct expr* index) {
    struct expr* e  = expr_create(EXPR_ARRAY_SUB, 0, 0);
    e->left  = ident;
    e->right = index;
    return e;
}



/* print */


void expr_print( struct expr *e ) {
    if (!e) return;
    switch(e->kind){
        case EXPR_INT_LITERAL:
            printf("%d", e->int_literal);
            break;
        case EXPR_STRING_LITERAL: 
            fprintf(stdout, "%s", e->string_literal);
            break;
        case EXPR_CHAR_LITERAL:
            fprintf(stdout, "%s", e->char_literal);
            break;
        case EXPR_FLOAT_LITERAL:
            fprintf(stdout, "%f", e->float_literal);
            break;
        case EXPR_BOOL:
            fprintf(stdout, "%s", e->bool_literal ? "true" : "false");
            break;
        case EXPR_ARRAY_INIT:
            fprintf(stdout, "{");
            expr_print_list(e, ", ");
            fprintf(stdout, "}");
        case EXPR_ARRAY_SUB:
            fprintf(stdout, "%s", e->left->ident);
            fprintf(stdout, "[");
            expr_print(e->right);
            fprintf(stdout, "%s", "]");
            struct expr* c = e->right->right;
            while (c) {
                fprintf(stdout, "[");
                expr_print(c);
                fprintf(stdout, "%s", "]");
                c = c->right;    
            }
            break;
        case EXPR_ARG:
            expr_print(e->left);
            break;
        case EXPR_INC:
            expr_print(e->left);
            fprintf(stdout, "++");
            break;
        case EXPR_DEC:
            expr_print(e->left);
            fprintf(stdout, "--");
            break;
        case EXPR_ASSIGN:
            expr_print(e->left);
            fprintf(stdout, "=");
            expr_print(e->right);
            break;
        case EXPR_FUNC:
            expr_print(e->left);
            fprintf(stdout, "(");
            expr_print_list(e->right, ", ");
            fprintf(stdout, ")");
            break;
        case EXPR_IDENT:
            fprintf(stdout, "%s", e->ident);
            break;
        case EXPR_ADD:
            expr_print(e->left);
            fprintf(stdout, "+");
            expr_print(e->right);
            break;
        case EXPR_SUB:
            expr_print(e->left);
            fprintf(stdout, "-");
            expr_print(e->right);
            break;
        case EXPR_MULT:
            expr_print(e->left);
            fprintf(stdout, "*");
            expr_print(e->right);
            break;
        case EXPR_DIV:
            expr_print(e->left);
            fprintf(stdout, "/");
            expr_print(e->right);
            break;
        case EXPR_EXP:
            expr_print(e->left);
            fprintf(stdout, "^");
            expr_print(e->right);
            break;
        case EXPR_MOD:
            expr_print(e->left);
            fprintf(stdout, "%%");
            expr_print(e->right);
            break;
        case EXPR_LT:
            expr_print(e->left);
            fprintf(stdout, "<");
            expr_print(e->right);
            break;
        case EXPR_GT:
            expr_print(e->left);
            fprintf(stdout, ">");
            expr_print(e->right);
            break;
        case EXPR_LEQ:
            expr_print(e->left);
            fprintf(stdout, "<=");
            expr_print(e->right);
            break;
        case EXPR_GEQ:
            expr_print(e->left);
            fprintf(stdout, ">=");
            expr_print(e->right);
            break;
        case EXPR_EQ:
            expr_print(e->left);
            fprintf(stdout, "==");
            expr_print(e->right);
            break;
        case EXPR_NEQ:
            expr_print(e->left);
            fprintf(stdout, "!=");
            expr_print(e->right);
            break;
        case EXPR_AND:
            expr_print(e->left);
            fprintf(stdout, "&&");
            expr_print(e->right);
            break;
        case EXPR_OR:
            expr_print(e->left);
            fprintf(stdout, "||");
            expr_print(e->right);
            break;
        case EXPR_NOT:
            fprintf(stdout, "!");
            expr_print(e->left);
            break;
        case EXPR_NEG:
            fprintf(stdout, "-");
            expr_print(e->left);
            break;
        case EXPR_PLUS:
            fprintf(stdout, "+");
            expr_print(e->left);
            break;
    }
}


void expr_print_list(struct expr* e, char *delim) {
    if (!e) return;
    expr_print(e->left);
    if (e->right) fprintf(stdout, "%s", delim);
    expr_print_list(e->right, delim);
}
