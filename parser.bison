%{
#include <stdio.h>

extern char *yytext;
extern int yylex();
extern int yyerror( char *str );
%}

%token TOKEN_INT
%token TOKEN_PLUS
%token TOKEN_MINUS
%token TOKEN_MUL
%token TOKEN_DIV
%token TOKEN_LPAREN
%token TOKEN_RPAREN
%token TOKEN_SEMI
%token TOKEN_ERROR
%token TOKEN_EOF
%token TOKEN_ARRAY
%token TOKEN_AUTO
%token TOKEN_BOOL
%token TOKEN_CHAR
%token TOKEN_ELSE
%token TOKEN_FALSE
%token TOKEN_FLOAT
%token TOKEN_FOR
%token TOKEN_FUNC
%token TOKEN_IF
%token TOKEN_PRINT
%token TOKEN_RETURN
%token TOKEN_STR
%token TOKEN_TRUE
%token TOKEN_VOID
%token TOKEN_WHILE
%token TOKEN_ASSIGN
%token TOKEN_LBRACE
%token TOKEN_RBRACE
%token TOKEN_LBRACKET
%token TOKEN_RBRACKET
%token TOKEN_COMMA
%token TOKEN_INC
%token TOKEN_DEC
%token TOKEN_ADD
%token TOKEN_NEG
%token TOKEN_MULT
%token TOKEN_MOD
%token TOKEN_EXP
%token TOKEN_INEQ
%token TOKEN_EQ
%token TOKEN_NOT
%token TOKEN_LT
%token TOKEN_GT
%token TOKEN_LEQ
%token TOKEN_GEQ
%token TOKEN_AND
%token TOKEN_OR
%token TOKEN_DEFINE
%token TOKEN_SEMICOLON
%token TOKEN_IDENT
%token TOKEN_INT_LITERAL
%token TOKEN_FLOAT_LITERAL
%token TOKEN_STRING_LITERAL
%token TOKEN_CHAR_LITERAL
%token TOKEN_COMMENT
%%

program : decl_list TOKEN_EOF { return 0; }
| TOKEN_EOF { return 0; }
;

/*  Decl list (highest level thing)*/
decl_list : decl_list decl
| decl
;

/* func decl and var decls as bodies cannot have func decls */
decl : var_decl
| func_decl
;

/* Variable declarations */
var_decl:
/* To declare a normal variable with a type (stmts)*/
TOKEN_IDENT TOKEN_DEFINE val_type init expr_val TOKEN_SEMICOLON
| TOKEN_IDENT TOKEN_DEFINE val_type TOKEN_SEMICOLON
/*  Array decl */
| TOKEN_IDENT TOKEN_DEFINE array_type init TOKEN_LBRACE expr_list TOKEN_RBRACE TOKEN_SEMICOLON
/*  Array */
| TOKEN_IDENT TOKEN_DEFINE array_type TOKEN_SEMICOLON
;

/* Function declarations */
func_decl: 
/*  Func prototype */
TOKEN_IDENT TOKEN_DEFINE TOKEN_FUNC return_type TOKEN_LPAREN param_list TOKEN_RPAREN TOKEN_SEMICOLON
/*  Func assignment */
| TOKEN_IDENT TOKEN_DEFINE TOKEN_FUNC return_type TOKEN_LPAREN param_list TOKEN_RPAREN TOKEN_ASSIGN TOKEN_LBRACE stmt_list TOKEN_RBRACE
;

/* Statement lists (inside of bodies) */
stmt_list : stmt_list stmt
|
;

if_dangle: TOKEN_IF TOKEN_LPAREN expr TOKEN_RPAREN if_dangle TOKEN_ELSE if_dangle
| var_decl
| for_stmt dangle_end
| func_call TOKEN_SEMICOLON
| TOKEN_LBRACE stmt_list TOKEN_RBRACE
| expr_assign TOKEN_SEMICOLON
| TOKEN_RETURN TOKEN_SEMICOLON
| TOKEN_PRINT expr_list TOKEN_SEMICOLON
| inc_or_dec TOKEN_SEMICOLON
;

dangle_end: TOKEN_SEMICOLON
| if_dangle
;

/* Statements (make up body), decls turn into this */
stmt : var_decl
| TOKEN_LBRACE stmt_list TOKEN_RBRACE
| TOKEN_IF TOKEN_LPAREN expr TOKEN_RPAREN stmt
| TOKEN_IF TOKEN_LPAREN expr TOKEN_RPAREN if_dangle TOKEN_ELSE stmt
| for_stmt reg_end
| TOKEN_RETURN expr TOKEN_SEMICOLON
| TOKEN_RETURN TOKEN_SEMICOLON
| TOKEN_PRINT expr_list TOKEN_SEMICOLON
| inc_or_dec TOKEN_SEMICOLON
| expr_assign TOKEN_SEMICOLON
| func_call TOKEN_SEMICOLON
;

reg_end: TOKEN_SEMICOLON
| stmt
;

/* For loop statement */
for_stmt: TOKEN_FOR for_cond
;
for_cond: TOKEN_LPAREN for_expr TOKEN_SEMICOLON for_expr TOKEN_SEMICOLON for_expr TOKEN_RPAREN
;
for_expr: expr
|
;

func_call: TOKEN_IDENT TOKEN_LPAREN expr_list TOKEN_RPAREN
;

/* Expression list (func calls, print, etc.) */
expr_list : expr_val expr_next
|
;
expr_next : TOKEN_COMMA expr_list
|
;

/*  Expressions */
expr : expr_val
| expr_assign 
;

/*  Assignment expressions */
expr_assign: mut TOKEN_ASSIGN expr
;

/*  Expr for values */
expr_val: expr_val TOKEN_PLUS val_literal
| expr_val TOKEN_MINUS val_literal
| expr_val TOKEN_INEQ  val_literal
| expr_val TOKEN_EQ    val_literal
| expr_val TOKEN_LT    val_literal
| expr_val TOKEN_GT    val_literal
| expr_val TOKEN_LEQ   val_literal
| expr_val TOKEN_GEQ   val_literal
| expr_val TOKEN_AND   val_literal
| expr_val TOKEN_OR    val_literal
| expr_val TOKEN_MULT  val_literal
| expr_val TOKEN_DIV   val_literal
| expr_val TOKEN_ADD   val_literal
| expr_val TOKEN_MOD   val_literal
| expr_val TOKEN_NEG   val_literal
| expr_val TOKEN_EXP   val_literal
| val_literal
| inc_or_dec
;

inc_or_dec: TOKEN_IDENT TOKEN_INC
| TOKEN_IDENT TOKEN_DEC
;

/* Value literals */
val_literal : TOKEN_INT_LITERAL
| TOKEN_CHAR_LITERAL
| TOKEN_FLOAT_LITERAL
| TOKEN_STRING_LITERAL
| TOKEN_TRUE
| TOKEN_FALSE
| TOKEN_NOT val_literal
| TOKEN_NEG val_literal
| func_call
| TOKEN_LPAREN expr TOKEN_RPAREN
| mut
;

mut : TOKEN_IDENT
| array_access
;

array_access : TOKEN_IDENT TOKEN_LBRACKET expr_val TOKEN_RBRACKET array_access_next

array_access_next : TOKEN_LBRACKET expr_val TOKEN_RBRACKET array_access_next
|
;

/* Value types */
array_type : TOKEN_ARRAY TOKEN_LBRACKET array_size TOKEN_RBRACKET all_types

array_size : expr_val
|
;

all_types: val_type
| array_type
;

val_type : TOKEN_INT
| TOKEN_FLOAT
| TOKEN_BOOL
| TOKEN_CHAR
| TOKEN_STR
;

/* Function return types */
return_type : val_type
| TOKEN_VOID
;

/* Param lists (when declaring function) */
param_list : TOKEN_IDENT TOKEN_DEFINE all_types param_next
|
;
param_next : TOKEN_COMMA TOKEN_IDENT TOKEN_DEFINE all_types param_next
|
;


init: TOKEN_ASSIGN
;

%%

int yyerror(char *s) {
    printf("parse error: %s\n",s);
    return 1;
}
