#include "../include/stmt.h"
extern int ERR_COUNT;

struct stmt* stmt_create(stmt_t kind, struct decl* decl, struct expr* init_expr, struct expr* expr, struct expr* next_expr, struct stmt* body, struct stmt* else_body, struct stmt* next) {
    struct stmt* s;
    if (!(s = calloc(1, sizeof(struct stmt)))) {
        fprintf(stderr, "ERROR: Could not allocate enough memory for expr_create.\n");
        exit(EXIT_FAILURE);
    }
    s->kind       = kind;
    s->decl       = decl;
    s->init_expr  = init_expr;
    s->expr       = expr;
    s->next_expr  = next_expr;
    s->body       = body;
    s->else_body  = else_body;
    s->next       = next;
    return s;
}

void stmt_print(struct stmt* s, int indents, bool start_indent) {
    extern void indent(int indents);
    if (!s) return;
    if (start_indent) indent(indents);
    bool has_block;

    switch (s->kind) {
        case STMT_DECL:
            decl_print(s->decl, indents);
            break;
        case STMT_EXPR:
            expr_print(s->expr);
            fprintf(stdout, ";");
            break;
        case STMT_IF_ELSE:
            fprintf(stdout, "if (");
            expr_print(s->expr);
            fprintf(stdout, ")");
            has_block = (s->body->kind == STMT_BLOCK);
            fprintf(stdout, "%s", has_block ? " " : "\n");
            stmt_print(s->body, indents + !has_block, !has_block);
            if(!s->else_body) break;
            // If its a one line if statement with no block with an else, then new line and indent
            if (!has_block) {
                fprintf(stdout, "\n");
                indent(indents);
                fprintf(stdout, "else");
            } else fprintf(stdout, " else");
            has_block = (s->else_body->kind == STMT_BLOCK);
            /* Check if its an else if statement 
             * 
             * If a else statement has no body && the body == STMT_IF_ELSE, then its a if else statement
             * 
             * */
            if (!has_block && s->else_body->kind == STMT_IF_ELSE) {
                fprintf(stdout, " ");
                stmt_print(s->else_body, indents, 0);
                break;
            }
            fprintf(stdout, "%s", has_block ? " " : "\n");
            stmt_print(s->else_body, indents + !has_block, !has_block);
            break;
        case STMT_FOR:
            fprintf(stdout, "for (");
            expr_print(s->init_expr);
            fprintf(stdout, ";");
            expr_print(s->expr);
            fprintf(stdout, ";");
            expr_print(s->next_expr);
            fprintf(stdout, ")");
            has_block = (s->body->kind == STMT_BLOCK);
            fprintf(stdout, "%s", has_block ? " " : "\n");
            stmt_print(s->body, indents + !has_block, !has_block);
            break;
        case STMT_PRINT:
            fprintf(stdout, "print ");
            expr_print_list(s->expr);
            fprintf(stdout, ";");
            break;
        case STMT_RETURN:
            fprintf(stdout, "return ");
            expr_print(s->expr);
            fprintf(stdout, ";");
            break;
	    case STMT_BLOCK:
	        fprintf(stdout, "{\n");
	        stmt_print_list(s->body, indents + 1);
	        indent(indents);
	        printf("}");
	        break;
    }
}

/* Printing stmt lists */
void stmt_print_list(struct stmt* s, int indents){
    if (!s) return;

    stmt_print(s, indents, true);
    fprintf(stdout, "%s", "\n");
    stmt_print_list(s->next, indents);
}

/* Name resolution for stmt */
void stmt_resolve(struct stmt* s) {
    if (!s) return;
    switch (s->kind) {
        case STMT_DECL:
            decl_resolve(s->decl);
            break;
        case STMT_EXPR:
            expr_resolve(s->expr);
            break;
        case STMT_IF_ELSE:
            expr_resolve(s->expr);
            stmt_resolve(s->body);
            stmt_resolve(s->else_body);
            break;
        case STMT_FOR:
            expr_resolve(s->init_expr);
            expr_resolve(s->expr);
            expr_resolve(s->next_expr);
            stmt_resolve(s->body);
            break;
        case STMT_PRINT:
            expr_resolve(s->expr);
            break;
        case STMT_RETURN:
            expr_resolve(s->expr);
            break;
        case STMT_BLOCK:
            /* Create new scope */
            scope_enter();
            stmt_resolve(s->body);
            scope_exit();
            break;
        }
    stmt_resolve(s->next);
}

/* Function to type check statements recursively */
void stmt_typecheck(struct stmt* s, struct symbol *sym) {
    if (!s) return;

    struct type* t = {0};
    switch (s->kind){
        case STMT_DECL:
            decl_typecheck(s->decl);
            break;
        case STMT_EXPR:
            // Delete the type, done using it now
            type_delete(expr_typecheck(s->expr));
            break;
        case STMT_IF_ELSE:
            if ((t = expr_typecheck(s->expr))->kind != TYPE_BOOL) {
                fprintf(stderr, "Type Error: If condition must be boolean, given ");
                type_print(t);
                fprintf(stderr, " (");
                expr_print(s->expr);
                fprintf(stderr, ")\n");
                ERR_COUNT++;
            }
            type_delete(t);
            stmt_typecheck(s->body, sym);
            stmt_typecheck(s->else_body, sym);
            break;
        case STMT_FOR:
            // Only need to check that middle expr is a condition
            if ((t = expr_typecheck(s->expr))->kind != TYPE_BOOL) {
                fprintf(stderr, "Type Error: Middle condition of for loop must be boolean, given ");
                type_print(t);
                fprintf(stderr, " (");
                expr_print(s->expr);
                fprintf(stderr, ")\n");
                ERR_COUNT++;
            }
            type_delete(t);
            // TODO: May need to delete init and next exprs? But never call them..
            stmt_typecheck(s->body, sym);
            break;
        case STMT_PRINT:
            for (struct expr* e = s->expr; e; e = e->right) { 
                t = expr_typecheck(e->left);
                if (t->kind == TYPE_VOID || t->kind == TYPE_ARRAY || t->kind == TYPE_FUNC) {
                    //TODO
                    fprintf(stderr, "Type Error: Cannot print type [void..array..etc]");
                    ERR_COUNT++;
                }
                type_delete(t);
            }
            break;
        case STMT_RETURN:
            // Parsing will handle if the return types is not one of the four atomic types + void
            if ((t = expr_typecheck(s->expr))->kind != sym->type->subtype->kind) {
                // TODO:
                fprintf(stderr, "Type Error: Return type does not match...");
                ERR_COUNT++;
            }
            type_delete(t);
            break;
        case STMT_BLOCK:
            stmt_typecheck(s->body, sym);
            break;
    }
    stmt_typecheck(s->next, sym);
}
