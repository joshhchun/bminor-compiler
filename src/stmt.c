#include "../include/stmt.h"
#include "../include/bminor.h"


void stmt_print_list(struct stmt *s, int indents, char *delim);

struct stmt* stmt_create(stmt_t kind, struct decl* decl, struct expr* init_expr, struct expr* expr, struct expr* next_expr, struct stmt *body, struct stmt *else_body, struct stmt *next ) {
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

void stmt_print( struct stmt *s, int indents, bool start_indent) {
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
            expr_print_list(s->expr, ", ");
            fprintf(stdout, ";");
            break;
        case STMT_RETURN:
            fprintf(stdout, "return ");
            expr_print(s->expr);
            fprintf(stdout, ";");
            break;
	    case STMT_BLOCK:
	        fprintf(stdout, "{\n");
	        stmt_print_list(s->body, indents + 1, "\n");
	        indent(indents);
	        printf("}");
	        break;
    }
}
void stmt_print_list(struct stmt *s, int indents, char *delim){
    if (!s) return;

    stmt_print(s, indents, true);
    fprintf(stdout, "%s", delim);
    stmt_print_list(s->next, indents, delim);
}
