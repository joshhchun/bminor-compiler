#ifndef EXPR_H
#define EXPR_H

#include "symbol.h"
#include "encode.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef enum {
    /* Ops */
    EXPR_ADD,
    EXPR_SUB,
    EXPR_MULT,
    EXPR_DIV,
    EXPR_EXP,
    EXPR_MOD,

    /* Literals */
    EXPR_INT_LITERAL,
    EXPR_FLOAT_LITERAL,
    EXPR_CHAR_LITERAL,
    EXPR_STRING_LITERAL,
    EXPR_INC,
    EXPR_DEC,
    EXPR_BOOL,
    EXPR_FUNC,
    EXPR_ARRAY_SUB,
    EXPR_IDENT,
    /* TODO: What to do with parenthesis? */

    /* Inequaliies */
    EXPR_LT,
    EXPR_GT,
    EXPR_LEQ,
    EXPR_GEQ,
    EXPR_EQ,
    EXPR_NEQ,
    
    /* Assignment */
    EXPR_ASSIGN,

    /* Logical ops */
    EXPR_AND,
    EXPR_OR,

    /* Unary */
    EXPR_NOT,
    EXPR_NEG,
    EXPR_PLUS,

    /* Args */
    EXPR_ARRAY_INIT,
    EXPR_ARG,
} expr_t;

struct expr {
	/* used by all kinds of exprs */
	expr_t kind;
	struct expr *left;
	struct expr *right;

	/* used by various leaf exprs */
	const char *ident;
	int int_literal;
	const char * string_literal;
	float float_literal;
	char* char_literal;
	bool bool_literal;
	struct symbol *symbol;
};

struct expr * expr_create( expr_t kind, struct expr *left, struct expr *right );


struct expr* expr_create_array_sub(struct expr* ident, struct expr* index);
struct expr* expr_create_ident(const char *n);

struct expr * expr_create_integer_literal( int c );
struct expr * expr_create_bool_literal( int c );
struct expr * expr_create_char_literal( char* c );
struct expr * expr_create_float_literal( float c );
struct expr * expr_create_string_literal( const char *str );

void expr_print( struct expr *e );

#endif
