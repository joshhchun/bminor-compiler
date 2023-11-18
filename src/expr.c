#include "../include/expr.h"

extern int ERR_COUNT;

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
        exit(EXIT_FAILURE);
    }
    e->char_literal = dup_string;
    return e;
}
struct expr* expr_create_string_literal(const char *str) {
    struct expr* e = expr_create(EXPR_STRING_LITERAL, 0, 0);
    char *dup_string = strdup(str);
    if (!dup_string) {
        fprintf(stderr, "ERROR: Not enough space to allocate string literal.\n");
        exit(EXIT_FAILURE);
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

struct expr* shave_parens(struct expr* e) {
    while (e && e->kind == EXPR_PAREN) {
        e = e->right;
    }
    return e;
}

/* Printing expressions */
void expr_print( struct expr *e ) {
    if (!e) return;
    switch(e->kind){
        /* Literals */
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
        case EXPR_PAREN:
            e = shave_parens(e->right);
            fprintf(stdout, "(");
            expr_print(e);
            fprintf(stdout, ")");
            break;
        /* Array inits */
        case EXPR_ARRAY_INIT:
            fprintf(stdout, "{");
            expr_print_list(e->left);
            fprintf(stdout, "}");
            break;
        /* Array subscripts */
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
        /* Arguments for expr_lists */
        case EXPR_ARG:
            expr_print(e->left);
            break;
        /* Inc and decs */
        case EXPR_INC:
            expr_print(e->left);
            fprintf(stdout, "++");
            break;
        case EXPR_DEC:
            expr_print(e->left);
            fprintf(stdout, "--");
            break;
        /* Assignment */
        case EXPR_ASSIGN:
            expr_print(e->left);
            fprintf(stdout, "=");
            expr_print(e->right);
            break;
        /* Function calls */
        case EXPR_FUNC:
            expr_print(e->left);
            fprintf(stdout, "(");
            expr_print_list(e->right);
            fprintf(stdout, ")");
            break;
        /* Identifiers */
        case EXPR_IDENT:
            fprintf(stdout, "%s", e->ident);
            break;
        /* Operations */
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
        /* Unary */
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

/* Printing expression lists */
void expr_print_list(struct expr* e) {
    if (!e) return;
    expr_print(e);
    if (e->right) fprintf(stdout, "%s", ", ");
    expr_print_list(e->right);
}

/* Name resolution for expr */
void expr_resolve (struct expr* e) {
    if (!e) return;
    if (e->kind == EXPR_IDENT) {
        if (!(e->symbol = scope_lookup(e->ident))) {
            fprintf(stderr, "Resolve Error: Unknown ident: %s.\n", e->ident);
            ERR_COUNT++;
        } else {
            symbol_print(e->symbol);
        }
    } else {
        expr_resolve(e->left);
        expr_resolve(e->right);
    }
}

/* Internal helper function for printing type error messages with arithmetic operations */
void expr_arith_error(expr_t kind, struct expr* e, struct type* lt, struct type* rt) {
    char* operations[] = {"add", "subtract", "multiply", "divide", "exponentiate", "modulo"};
    char* op = operations[kind - EXPR_ADD];

    fprintf(stdout, "Type Error: Cannot %s between ", op);
    expr_type_print(e->left, lt);
    fprintf(stdout, " and ");
    expr_type_println(e->right, rt);
}

/* Internal helper function to help print type error messages for comparisons */
void expr_comp_error(expr_t kind, struct expr* e, struct type* lt, struct type* rt) {
    char* comparisons[] = {"<", ">", "<=", ">=", "==", "!="};
    char* comp = comparisons[kind - EXPR_LT];

    fprintf(stdout, "Type Error: Cannot compare (%s) between ", comp);
    expr_type_print(e->left, lt);
    fprintf(stdout, " and ");
    expr_type_println(e->right, rt);
}

/* Internal helping function to help print expressions with their types */
void expr_type_print(struct expr* e, struct type* t) {
    type_print(t);
    fprintf(stdout, " (");
    expr_print(e);
    fprintf(stdout, ")");
}

/* Internal helping function to help print expressions with their types (with new line)*/
void expr_type_println(struct expr* e, struct type* t) {
    type_print(t);
    fprintf(stdout, " (");
    expr_print(e);
    fprintf(stdout, ")\n");
}

struct type* expr_typecheck(struct expr* e) {
    if (!e) return 0;

    struct type* lt = expr_typecheck(e->left);
    struct type* rt = expr_typecheck(e->right);

    struct type* result = 0;
    switch (e->kind) {
        case EXPR_ADD:
            if (lt->kind != rt->kind || (lt->kind != TYPE_INT && lt->kind != TYPE_FLOAT)) {
                expr_arith_error(e->kind, e, lt, rt);
                ERR_COUNT++;
                result = type_create(TYPE_INT, 0, 0);
            } else
                result = type_create(lt->kind, 0, 0);
            break;
        case EXPR_SUB:
            if (lt->kind != rt->kind || (lt->kind != TYPE_INT && lt->kind != TYPE_FLOAT)) {
                expr_arith_error(e->kind, e, lt, rt);
                ERR_COUNT++;
                result = type_create(TYPE_INT, 0, 0);
            } else
                result = type_create(lt->kind, 0, 0);
            break;
        case EXPR_MULT:
            if (lt->kind != rt->kind || (lt->kind != TYPE_INT && lt->kind != TYPE_FLOAT)) {
                expr_arith_error(e->kind, e, lt, rt);
                ERR_COUNT++;
                result = type_create(TYPE_INT, 0, 0);
            } else
                result = type_create(lt->kind, 0, 0);
            break;
        case EXPR_DIV:
            if (lt->kind != rt->kind || (lt->kind != TYPE_INT && lt->kind != TYPE_FLOAT)) {
                expr_arith_error(e->kind, e, lt, rt);
                ERR_COUNT++;
                result = type_create(TYPE_INT, 0, 0);
            } else
                result = type_create(lt->kind, 0, 0);
            break;
        case EXPR_EXP:
            if (lt->kind != rt->kind || (lt->kind != TYPE_INT && lt->kind != TYPE_FLOAT)) {
                expr_arith_error(e->kind, e, lt, rt);
                ERR_COUNT++;
                result = type_create(TYPE_INT, 0, 0);
            } else
                result = type_create(lt->kind, 0, 0);
            break;
        case EXPR_MOD:
            /* Modulo only works with integers */
            if (lt->kind != rt->kind || lt->kind != TYPE_INT) {
                expr_arith_error(e->kind, e, lt, rt);
                ERR_COUNT++;
                result = type_create(TYPE_INT, 0, 0);
            } else
                result = type_create(lt->kind, 0, 0);
            break;
        case EXPR_INT_LITERAL:
            result = type_create(TYPE_INT, 0, 0);
            break;
        case EXPR_FLOAT_LITERAL:
            result = type_create(TYPE_FLOAT, 0, 0);
            break;
        case EXPR_CHAR_LITERAL:
            result = type_create(TYPE_CHAR, 0, 0);
            break;
        case EXPR_STRING_LITERAL:
            result = type_create(TYPE_STR, 0, 0);
            break;
        case EXPR_INC:
            if (lt->kind != TYPE_INT) {
                fprintf(stdout, "Type Error: Can only postfix increment with integers, given: ");
                expr_type_println(e->left, lt);
                ERR_COUNT++;
            }
            result = type_create(TYPE_INT, 0, 0);
            break;
        case EXPR_DEC:
            if (lt->kind != TYPE_INT) {
                fprintf(stdout, "Type Error: Can only postfix decrement with integers, given: ");
                expr_type_println(e->left, lt);
                ERR_COUNT++;
            }
            result = type_create(TYPE_INT, 0, 0);
            break;
        case EXPR_BOOL:
            result = type_create(TYPE_BOOL, 0, 0);
            break;
        case EXPR_FUNC:
            // Check if the ident is a valid function
            if (lt->kind != TYPE_FUNC) {
                fprintf(stdout, "Type Error: Unknown function: ");
                expr_type_println(e, 0);
                ERR_COUNT++;
                result = type_copy(lt);
            } else if (!e->left->symbol->func_defined) {
                fprintf(stdout, "Type Error: Function not declared: ");
                expr_type_println(e, 0);
                ERR_COUNT++;
                result = type_copy(lt->subtype);
            } else {
                // Make sure that the arguments and param matches
                struct expr* arg         = e->right;  
                struct param_list* param = lt->params;
                struct type *arg_type, *param_type;
                for (; arg || param; arg = arg->right, param = param->next) {
                    if (!arg   && ERR_COUNT++) fprintf(stdout, "Type Error: Not enough arguments to function (%s)\n", e->left->ident);
                    if (!param && ERR_COUNT++) fprintf(stdout, "Type Error: Too many arguments to function (%s)\n", e->left->ident);
                    arg_type   = expr_typecheck(arg->left);
                    param_type = param->type;
                    if (!type_same(arg_type, param_type)) {
                        fprintf(stdout, "Type Error: Argument of type ");
                        expr_type_print(arg, arg_type);
                        fprintf(stdout, " does not match parameter type of ");
                        type_print(param_type);
                        fprintf(stdout, " (%s) in function (%s)\n", param->ident, e->left->ident);
                        ERR_COUNT++;
                    }
                }
                result = type_copy(lt->subtype);
            }
            break; 
        case EXPR_ARRAY_SUB:
            if (lt->kind != TYPE_ARRAY) {
                fprintf(stdout, "Type Error: Cannot subscript into a non array type, given: ");
                expr_type_println(e->left, lt);
                ERR_COUNT++;
                result = type_copy(lt);
            } else {
                struct expr* arg = e->right;
                struct type* final_type = lt;
                // Go through the subs and subtypes to get the correct type
                for (struct type* t = lt->subtype; arg; final_type = t, arg = arg->right, t = t->subtype)  {
                    if (!t) {
                        // Too many subs, error message
                        fprintf(stdout, "Type Error: Too many subscripts into array type of ");
                        expr_type_println(e->left, lt);
                        ERR_COUNT++;
                        break;
                    }
                    // Need to make sure that the index is type integer
                    if (expr_typecheck(arg)->kind != TYPE_INT) {
                        fprintf(stdout, "Type Error: Must use integer to subscript into array, given: ");
                        expr_type_println(e->left, t);
                        ERR_COUNT++;
                    }
                }
                // Should be the last subscript, but just in case of error just take the last type ?
                result = type_copy(final_type);
            }
            break;
        case EXPR_IDENT:
            result = type_copy(e->symbol->type);
            break;
        case EXPR_PAREN:
            result = type_copy(rt);
            break;
        case EXPR_LT:
            if (lt->kind != rt->kind || (lt->kind != TYPE_INT && lt->kind != TYPE_FLOAT)) {
                expr_comp_error(e->kind, e, lt, rt);
                ERR_COUNT++;
            }
            result = type_create(TYPE_BOOL, 0, 0);
            break;
        case EXPR_GT:
            if (lt->kind != rt->kind || (lt->kind != TYPE_INT && lt->kind != TYPE_FLOAT)) {
                expr_comp_error(e->kind, e, lt, rt);
                ERR_COUNT++;
            }
            result = type_create(TYPE_BOOL, 0, 0);
            break;
        case EXPR_LEQ:
            if (lt->kind != rt->kind || (lt->kind != TYPE_INT && lt->kind != TYPE_FLOAT)) {
                expr_comp_error(e->kind, e, lt, rt);
                ERR_COUNT++;
            }
            result = type_create(TYPE_BOOL, 0, 0);
            break;
        case EXPR_GEQ:
            if (lt->kind != rt->kind || (lt->kind != TYPE_INT && lt->kind != TYPE_FLOAT)) {
                expr_comp_error(e->kind, e, lt, rt);
                ERR_COUNT++;
            }
            result = type_create(TYPE_BOOL, 0, 0);
            break;
        case EXPR_EQ:
            if (lt->kind != rt->kind || lt->kind == TYPE_VOID || lt->kind == TYPE_FUNC || lt->kind == TYPE_ARRAY) {
                expr_comp_error(e->kind, e, lt, rt);
                ERR_COUNT++;
            }
            result = type_create(TYPE_BOOL, 0, 0);
            break;
        case EXPR_NEQ:
            if (lt->kind != rt->kind || lt->kind == TYPE_VOID || lt->kind == TYPE_FUNC || lt->kind == TYPE_ARRAY) {
                expr_comp_error(e->kind, e, lt, rt);
                ERR_COUNT++;
            }
            result = type_create(TYPE_BOOL, 0, 0);
            break;
        case EXPR_ASSIGN:
            if (lt->kind != rt->kind) {
                fprintf(stdout, "Type Error: Cannot assign ");
                expr_type_print(e->right, rt);
                fprintf(stdout, " to ");
                expr_type_println(e->left, lt);
                ERR_COUNT++;
            }
            result = type_copy(lt);
            break;
        case EXPR_AND:
            if (lt->kind != rt->kind || lt->kind != TYPE_BOOL) {
                fprintf(stdout, "Type Error: Cannot do logical comparison (&&) between ");
                expr_type_print(e->left, lt);
                fprintf(stdout, " and ");
                expr_type_println(e->right, rt);
                ERR_COUNT++;
            }
            result = type_create(TYPE_BOOL, 0, 0);
            break;
        case EXPR_OR:
            if (lt->kind != rt->kind || lt->kind != TYPE_BOOL) {
                fprintf(stdout, "Type Error: Cannot do logical comparison (||) between ");
                expr_type_print(e->left, lt);
                fprintf(stdout, " and ");
                expr_type_println(e->right, rt);
                ERR_COUNT++;
            }
            result = type_create(TYPE_BOOL, 0, 0);
            break;
        case EXPR_NOT:
            if (lt->kind != TYPE_BOOL) {
                fprintf(stdout, "Type Error: Cannot use logical not (!) on ");
                expr_type_println(e->left, lt);
                ERR_COUNT++;
            }
            result = type_create(TYPE_BOOL, 0, 0);
            break;
        case EXPR_NEG:
            if (lt->kind != TYPE_INT && lt->kind != TYPE_FLOAT) {
                fprintf(stdout, "Type Error: Cannot use unary operator (-) on ");
                expr_type_println(e->left, lt);
                ERR_COUNT++;
                result = type_create(TYPE_INT, 0, 0);
            } else
                result = type_create(lt->kind, 0, 0);
            break;
        case EXPR_PLUS:
            if (lt->kind != TYPE_INT && lt->kind != TYPE_FLOAT) {
                fprintf(stdout, "Type Error: Cannot use unary operator (+) on ");
                expr_type_println(e->left, lt);
                ERR_COUNT++;
                result = type_create(TYPE_INT, 0, 0);
            } else
                result = type_create(lt->kind, 0, 0);
            break;
        case EXPR_ARRAY_INIT:
            // Handled in decl_typecheck
            break;
        case EXPR_ARG:
            result = type_create(lt->kind, 0, 0);
            break;
        }
    return result;
}
