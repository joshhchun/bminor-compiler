#include "../include/stmt.h"
#include "../include/bminor.h"

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

void stmt_print( struct stmt *s, int indents ) {
    if (!s) return;
    indent(indents);

    switch (s->kind) {
        case STMT_DECL:
            decl_print(s->decl, indents);
            break;
        case STMT_EXPR:
            expr_print(s->expr);
            break;
        case STMT_IF_ELSE:
            fprintf(stdout, "if (");
            expr_print(s->expr);
            fprintf(stdout, ")");
            stmt_print(s->body, indents);
            if(!s->else_body) break;
            fprintf(stdout, "else ");
            stmt_print(s->else_body, indents);
            break;
        case STMT_FOR:
            fprintf(stdout, "for (");
            expr_print(s->init_expr);
            fprintf(stdout, ";");
            expr_print(s->expr);
            fprintf(stdout, ";");
            expr_print(s->next_expr);
            fprintf(stdout, ")");
            stmt_print(s->body, indents);
            break;
        case STMT_PRINT:
            fprintf(stdout, "print ");
            expr_print(s->expr);
            fprintf(stdout, ";\n");
            break;
        case STMT_RETURN:
            fprintf(stdout, "return ");
            expr_print(s->expr);
            fprintf(stdout, ";\n");
            break;
	    case STMT_BLOCK:
	        fprintf(stdout, "{\n");
	        stmt_print(s->body, indents + 1);
	        printf("}\n");
	        break;
    }
	stmt_print(s->next, indents);
}
