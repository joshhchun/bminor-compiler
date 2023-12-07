#include "../include/expr.h"

extern int ERR_COUNT;
const char* arg_names[6] = {"%rdi", "%rsi", "%rdx", "%rcx", "%r8", "%r9"};

void caller_save_argregs() {
    
    

}

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
struct expr* expr_create_char_literal(uint8_t c) {
    struct expr* e = expr_create(EXPR_CHAR_LITERAL, 0, 0);
    e->char_literal = c;
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
        case EXPR_CHAR_LITERAL: {
            char buf[BUFSIZ] = {0};
            char_encode((char)e->char_literal, buf);
            fprintf(stdout, "%s", buf);
            break;
        }
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

// Creates and returns a register with the memory address of the array reference
// TODO: Maybe check arr bounds here?
int array_idx_mem(int base_addr_reg, struct expr* arg) {
    // Generate reg for the index
    expr_codegen(arg->left);

    // Assuming all elements are 8 bytes right now...
    char buf[BUFSIZ] = {0};
    sprintf(buf, "0(%s, %s, 8)", scratch_name(base_addr_reg), scratch_name(arg->left->reg));
    int mem_reg = scratch_alloc();

    // Move the address into the reg
    printf("LEAQ %s, %s\n", buf, scratch_name(mem_reg));
    
    // Should be able to free these now, only need mem_reg
    scratch_free(base_addr_reg);
    scratch_free(arg->left->reg);

    if (arg->right) {
        mem_reg = array_idx_mem(mem_reg, arg->right);
    }
    return mem_reg;
}

void caller_save_regs() {
    printf("PUSH %%rdi\n");
    printf("PUSH %%rsi\n");
    printf("PUSH %%rdx\n");
    printf("PUSH %%rcx\n");
    printf("PUSH %%r8\n");
    printf("PUSH %%r9\n");

    printf("PUSH %%r10\n");
    printf("PUSH %%r11\n");
}

void caller_restore_regs() {
    printf("POP %%r11\n");
    printf("POP %%r10\n");

    printf("POP %%r9\n");
    printf("POP %%r8\n");
    printf("POP %%rcx\n");
    printf("POP %%rdx\n");
    printf("POP %%rsi\n");
    printf("POP %%rdi\n");
}

void expr_codegen(struct expr *e) {
    if (!e) return;
    switch(e->kind) {
        // Leaf node: allocate register and load value.
        case EXPR_IDENT:
            e->reg = scratch_alloc();
            printf("MOVQ %s, %s\n",
                symbol_codegen(e->symbol),
                scratch_name(e->reg));
            break;
        case EXPR_STRING_LITERAL: {
            //  .data
            //       .label
            //           .str "%s"
            //       .text
            const char* str_label = label_name(label_create());
            printf(".data\n");
            printf("%s\n", str_label);
            printf(".string \"%s\"\n", e->string_literal);
            printf(".text\n");
            
            e->reg = scratch_alloc();
            printf("MOVQ $%s, %s\n", str_label, scratch_name(e->reg));
            break;
        }
        case EXPR_FLOAT_LITERAL:
            e->reg = scratch_alloc();
            printf("MOVQ $%f, %s\n", e->float_literal, scratch_name(e->reg));
            break;
        // TODO: Maybe clean these val literals up? They all seem to be integers...
        case EXPR_BOOL:
            e->reg = scratch_alloc();
            printf("MOVQ $%d, %s\n", e->bool_literal, scratch_name(e->reg));
            break;
        case EXPR_INT_LITERAL:
            e->reg = scratch_alloc();
            printf("MOVQ $%d, %s\n", e->int_literal, scratch_name(e->reg));
            break;
        case EXPR_CHAR_LITERAL:
            //TODO: MOVB or MOVQ?
            e->reg = scratch_alloc();
            printf("MOVB $%u, %s\n", e->char_literal, scratch_name(e->reg));
            break;
        // Interior node: generate children, then add them.
        case EXPR_ADD:
            expr_codegen(e->left);
            expr_codegen(e->right);
            printf("ADDQ %s, %s\n",
                scratch_name(e->left->reg),
                scratch_name(e->right->reg));
            e->reg = e->right->reg;
            scratch_free(e->left->reg);
            break;
        case EXPR_SUB:
            expr_codegen(e->left);
            expr_codegen(e->right);
            printf("SUBQ %s, %s\n",
                scratch_name(e->left->reg),
                scratch_name(e->right->reg));
            e->reg = e->right->reg;
            scratch_free(e->left->reg);
            break;
        case EXPR_MULT:
            expr_codegen(e->left);
            expr_codegen(e->right);
            printf("MOVQ %s, %%rax\n", scratch_name(e->left->reg));
            printf("IMUL %s\n",       scratch_name(e->right->reg));
            printf("MOVQ %%rax, %s\n",   scratch_name(e->right->reg));
            e->reg = e->right->reg;
            scratch_free(e->left->reg);
            break;
        case EXPR_DIV:
            expr_codegen(e->left);
            expr_codegen(e->right);
            printf("MOVQ %s, %%rax\n", scratch_name(e->left->reg));
            printf("CQO\n");
            printf("IDIVQ %s\n", scratch_name(e->right->reg));
            printf("MOVQ %%rax, %s\n", scratch_name(e->right->reg));
            e->reg = e->right->reg;
            scratch_free(e->left->reg);
            break;
        case EXPR_MOD:
            expr_codegen(e->left);
            expr_codegen(e->right);
            printf("MOVQ %s, %%rax\n", scratch_name(e->left->reg));
            printf("CQO\n");
            printf("IDIVQ %s\n", scratch_name(e->right->reg));
            printf("MOVQ %%rdx, %s\n", scratch_name(e->right->reg));
            e->reg = e->right->reg;
            scratch_free(e->left->reg);
            break;
        case EXPR_INC:
            expr_codegen(e->left);
            printf("INCQ %s\n", scratch_name(e->left->reg));
            e->reg = e->left->reg;
            break;
        case EXPR_DEC:
            expr_codegen(e->left);
            printf("DEQQ %s\n", scratch_name(e->left->reg));
            e->reg = e->left->reg;
            break;
        case EXPR_EXP:
            // TODO: Don't know how to do exp yet
        case EXPR_ASSIGN:
            // TODO: This might be flipped
            expr_codegen(e->right);
            // If its an array...
            if (e->left->kind == EXPR_ARRAY_SUB) {
                // Need the memory address of the specific thing
                int base_addr_reg = scratch_alloc();
                // Move the initial base address of the array into a scratch reg
                printf("LEAQ %s, %s\n", symbol_codegen(e->left->symbol), scratch_name(base_addr_reg));
                // Should hold a register with the final memory address of the specified ref
                int final_idx_ref = array_idx_mem(base_addr_reg, e->right);
                // TODO: Might be backwards, maybe need a []
                printf("MOVQ %s, %s\n", scratch_name(e->right->reg), scratch_name(final_idx_ref));

                // Store the assigned value to the right reg...
                e->right->reg = final_idx_ref;
                scratch_free(e->left->reg);
                scratch_free(base_addr_reg);
                scratch_free(final_idx_ref);
            } else {
                // TODO: Possible only move 1 byte MOVB is if its a char or bool
                printf("MOVQ %s, %s\n",
                    scratch_name(e->right->reg),
                    symbol_codegen(e->left->symbol));
                e->reg = e->right->reg;
            }
            break;
        case EXPR_GT:
        case EXPR_LEQ:
        case EXPR_GEQ:
        case EXPR_EQ:
        case EXPR_NEQ:
        case EXPR_LT: {
            const char* true_label = label_name(label_create());
            const char* end_label  = label_name(label_create());
            expr_codegen(e->left);
            expr_codegen(e->right);
            printf("CMP %s, %s\n",
                    scratch_name(e->left->reg),
                    scratch_name(e->right->reg));
            switch (e->kind) {
                case EXPR_LT:
                    printf("JL %s\n", true_label);
                    break;
                case EXPR_GT:
                    printf("JG %s\n", true_label);
                    break;
                case EXPR_LEQ:
                    printf("JLE %s\n", true_label);
                    break;
                case EXPR_GEQ:
                    printf("JGE %s\n", true_label);
                    break;
                case EXPR_EQ:
                    printf("JE %s\n", true_label);
                    break;
                case EXPR_NEQ:
                    printf("JNE %s\n", true_label);
                    break;
                default:
                    printf("Unreachable\n");
                    exit(1);
            }
            printf("MOVQ $0, %s\n", scratch_name(e->right->reg));
            printf("JMP %s\n", end_label);

            // True label
            printf("%s:\n", true_label);
            printf("MOVQ $1, %s\n", scratch_name(e->right->reg));

            // End label (do nothing, pre-loaded it with false)
            printf("%s:\n", end_label);

            scratch_free(e->left->reg);
            e->reg = e->right->reg;
            break;
        }
        case EXPR_FUNC: {
            // Push caller-saved regs
            caller_save_regs();

            int i = 0;
            for (struct expr *arg = e->right; arg; arg = arg->right, i++) {
                expr_codegen(arg);
                // Move each argument into the registers
                printf("MOVQ %s, %s\n", arg_names[i], scratch_name(arg->reg));
                scratch_free(arg->reg);
            }
            printf("CALL %s\n", e->left->ident);

            // Restore caller saved regs
            caller_restore_regs();

            printf("MOVQ %%rax, %s\n", scratch_name(e->left->reg));
            e->reg = e->left->reg;
            scratch_free(e->right->reg);
            break;
        }
        case EXPR_ARRAY_SUB: {
            // Register should hold value of the array sub (e.g. a[5]) as assign ref is not handled here;
            int base_addr_reg = scratch_alloc();
            // Move the initial base address of the array into a scratch reg
            printf("LEAQ %s, %s\n", symbol_codegen(e->left->symbol), scratch_name(base_addr_reg));
            // Should hold a register with the final memory address of the specified ref
            int final_idx_ref = array_idx_mem(base_addr_reg, e->right);
            // Move the value of the ref address to a ref
            // TODO: Maybe store the result in a new reg vs left reg
            printf("MOVQ %s, %s\n", scratch_name(final_idx_ref), scratch_name(e->left->reg));

            e->reg = e->left->reg;
            scratch_free(e->right->reg);
            scratch_free(base_addr_reg);
            scratch_free(final_idx_ref);
            break;
         }
        case EXPR_PAREN:
            expr_codegen(e->left);
            e->reg = e->left->reg;
            break;
        case EXPR_NOT:
            expr_codegen(e->left);
            
            const char* true_label  = label_name(label_create());
            const char* done_label = label_name(label_create());

            printf("CMPQ $1, %s\n", scratch_name(e->left->reg));
            printf("JE %s\n", true_label);
            printf("MOVQ $1, %s\n", scratch_name(e->right->reg));
            printf("JMP %s\n", done_label);

            // True label
            printf("%s:\n", true_label);
            printf("MOVQ $0, %s\n", scratch_name(e->right->reg));

            // Done label
            printf("%s:\n", done_label);

            e->reg = e->right->reg;
            scratch_free(e->left->reg);
            break;
        case EXPR_AND: {
            expr_codegen(e->left);
            expr_codegen(e->right);
        
            const char* false_label = label_name(label_create());
            const char* done_label  = label_name(label_create());

            // Compare each boolean value to 0 to see if they are true
            printf("CMPQ $0, %s\n", scratch_name(e->left->reg));
            printf("JE %s\n", false_label);
            printf("CMPQ $0, %s\n", scratch_name(e->left->reg));
            printf("JE %s\n", false_label);

            // If the two are both true, then store $1 into the register and jump to end
            printf("MOVQ $1, %s\n", scratch_name(e->right->reg));
            printf("JMP %s\n", done_label);

            // False label (if one of the values was false)
            printf("%s:\n", false_label);
            printf("MOVEQ $0, %s\n", scratch_name(e->right->reg));

            // Done label
            printf("%s:\n", done_label);

            e->reg = e->right->reg;
            scratch_free(e->left->reg);
            break;
        }
        case EXPR_OR: {
            expr_codegen(e->left);
            expr_codegen(e->right);
        
            const char* true_label = label_name(label_create());
            const char* done_label  = label_name(label_create());

            // See if any of the values are true
            printf("CMPQ $1, %s\n", scratch_name(e->left->reg));
            printf("JE %s\n", true_label);
            printf("CMPQ $1, %s\n", scratch_name(e->left->reg));
            printf("JE %s\n", true_label);

            // If none are true then store a 0
            printf("MOVQ $0, %s\n", scratch_name(e->right->reg));
            printf("JMP %s\n", done_label);

            // True label (if one of the values was true)
            printf("%s:\n", true_label);
            printf("MOVEQ $1, %s\n", scratch_name(e->right->reg));

            // Done label
            printf("%s:\n", done_label);

            e->reg = e->right->reg;
            scratch_free(e->left->reg);
            break;
        }
        case EXPR_NEG:
            expr_codegen(e->left);
            printf("NEG %s\n", scratch_name(e->left->reg));
            e->reg = e->left->reg;
            break;
        case EXPR_PLUS:
            expr_codegen(e->left);
            e->reg = e->left->reg;
            break;
        case EXPR_ARRAY_INIT:
            // TODO: Probably handled in decl?
            break;
        case EXPR_ARG:
            expr_codegen(e->left);
            e->reg = e->left->reg;    
            break;
        default:
            printf("Unreachable.\n");
            exit(1);
        }
}

expr_t type_to_expr (type_t kind) {
    switch (kind) {
        case TYPE_BOOL:
            return EXPR_BOOL;
        case TYPE_CHAR:
            return EXPR_CHAR_LITERAL;
        case TYPE_INT:
            return EXPR_INT_LITERAL;
        case TYPE_STR:
            return EXPR_STRING_LITERAL;
        case TYPE_FUNC:
            printf("ERROR: Got type func in get_type, should not be possible.\n");
            exit(1);
            break;
        case TYPE_VOID:
            printf("ERROR: Got type void in get_type, should not be possible.\n");
            exit(1);
            break;
        case TYPE_ARRAY:
            // TODO: Array print impl?
            printf("ERROR: Array print not impl.\n");
            exit(1);
            break;
        case TYPE_FLOAT:
            printf("ERROR: Float print not impl.\n");
            exit(1);
            break;
    }
}

expr_t get_array_type (struct expr* e) {
    struct type* curr_t = e->left->symbol->type->subtype;
    for (; curr_t->subtype; curr_t = curr_t->subtype);
    return type_to_expr(curr_t->kind);
}

expr_t expr_get_type(struct expr* e) {
    switch (e->kind) {
        case EXPR_ADD:
        case EXPR_SUB:
        case EXPR_MULT:
        case EXPR_DIV:
        case EXPR_EXP:
        case EXPR_MOD:
        case EXPR_INC:
        case EXPR_NEG:
        case EXPR_DEC:
        case EXPR_PLUS:
        case EXPR_INT_LITERAL:
            return EXPR_INT_LITERAL;
        case EXPR_AND:
        case EXPR_OR:
        case EXPR_NOT:
        case EXPR_LT:
        case EXPR_GT:
        case EXPR_LEQ:
        case EXPR_GEQ:
        case EXPR_EQ:
        case EXPR_NEQ:
        case EXPR_BOOL:
            return EXPR_BOOL;
        case EXPR_CHAR_LITERAL:
            return EXPR_CHAR_LITERAL;
        case EXPR_STRING_LITERAL:
            return EXPR_STRING_LITERAL;
        case EXPR_FUNC:
            return type_to_expr(e->left->symbol->type->subtype->kind);
        case EXPR_ARRAY_SUB:
            return get_array_type(e);
        case EXPR_IDENT:
            return type_to_expr(e->symbol->type->kind);
        case EXPR_PAREN:
            return expr_get_type(e->right);
            break;
        case EXPR_ASSIGN:
            return expr_get_type(e->right);

        // Shouldn't come here as of now
        case EXPR_ARG:
            printf("ERROR: Should not be arg in print\n");
            break;
        case EXPR_FLOAT_LITERAL:
            printf("ERROR: Should not be float in print\n");
            break;
        case EXPR_ARRAY_INIT:
            printf("ERROR: Should not be arr init in print\n");
            break;
    }
    return -1;
}
