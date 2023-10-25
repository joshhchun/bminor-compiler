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

/* Variable decls and Function decls */
decl : var_decl
| func_decl
;

/* Variable declarations */
var_decl:
/* To declare a normal variable with a type (stmts)*/
TOKEN_IDENT TOKEN_DEFINE val_type init expr TOKEN_SEMICOLON
| TOKEN_IDENT TOKEN_DEFINE val_type TOKEN_SEMICOLON
/*  Array decl */
| TOKEN_IDENT TOKEN_DEFINE array_type init TOKEN_LBRACE array_init TOKEN_RBRACE TOKEN_SEMICOLON
/*  Array */
| TOKEN_IDENT TOKEN_DEFINE array_type TOKEN_SEMICOLON
;

/* Function declarations */
func_decl: 
/*  Func prototype */
TOKEN_IDENT TOKEN_DEFINE TOKEN_FUNC return_type TOKEN_LPAREN param_list TOKEN_RPAREN TOKEN_SEMICOLON
/*  Func assignment */
| TOKEN_IDENT TOKEN_DEFINE TOKEN_FUNC return_type TOKEN_LPAREN param_list TOKEN_RPAREN init TOKEN_LBRACE stmt_list TOKEN_RBRACE
;

/* Statement lists */
stmt_list : stmt_list stmt
|
;

/* Statements (make up decls) */
stmt: simp_stmt
| cmpd_stmt
;

/* Non right recursive statements */
simp_stmt : TOKEN_LBRACE stmt_list TOKEN_RBRACE
| var_decl
| TOKEN_RETURN expr TOKEN_SEMICOLON
| TOKEN_RETURN TOKEN_SEMICOLON
| TOKEN_PRINT opt_expr_list TOKEN_SEMICOLON
| inc_or_dec TOKEN_SEMICOLON
| expr_assign TOKEN_SEMICOLON
| func_call TOKEN_SEMICOLON
;

/* If and for statements */
cmpd_stmt : if_expr stmt
| if_expr if_dangle TOKEN_ELSE stmt
| for_stmt reg_end
;

/* Non dangling if statement */
if_dangle: if_expr if_dangle TOKEN_ELSE if_dangle
| for_stmt dangle_end
| simp_stmt
;

/* If statement expression condition */
if_expr: TOKEN_IF TOKEN_LPAREN expr TOKEN_RPAREN 
;

/* For loop statement */
for_stmt: TOKEN_FOR for_cond
;
for_cond: TOKEN_LPAREN for_expr TOKEN_SEMICOLON for_expr TOKEN_SEMICOLON for_expr TOKEN_RPAREN
;
for_expr: expr
|
;

/* For loop end if non dangling if statement */
dangle_end: TOKEN_SEMICOLON
| if_dangle
;

/* For loop end if regular if statement */
reg_end: TOKEN_SEMICOLON
| stmt
;

/* Calling a function */
func_call: TOKEN_IDENT TOKEN_LPAREN opt_expr_list TOKEN_RPAREN
;

/* Array inits, cannot be empty but can be nested */
array_init : TOKEN_LBRACE expr_list TOKEN_RBRACE array_init_next
| expr_list
;
array_init_next : TOKEN_COMMA TOKEN_LBRACE expr_list TOKEN_RBRACE array_init_next
|
;

/* Expression list (func calls, print, etc.) */
expr_list : expr expr_next
;

/* Optional expression list (can be empty) */
opt_expr_list : expr_list
|
;
expr_next : TOKEN_COMMA expr_list
|
;

/*  Expressions */
/*  Assignment expressions */
expr_assign: mut init expr
;
/* Expressions in order of lowest precedence to highest */
/* assign */
expr : expr_assign
| expr2
;
/* logical or */
expr2: expr2 TOKEN_OR expr3
| expr3
;
/* logical and */
expr3: expr3 TOKEN_AND expr4
| expr4
;
/* equality */
expr4: expr4 TOKEN_EQ expr5
| expr4 TOKEN_NOT TOKEN_EQ expr5
| expr5
;
/* equalities */
expr5: expr5 TOKEN_LT expr6
| expr5 TOKEN_GT expr6
| expr5 TOKEN_LEQ expr6
| expr5 TOKEN_GEQ expr6
| expr6
;
/* addition and subtraction */
expr6: expr6 TOKEN_ADD expr7
| expr6 TOKEN_NEG expr7
| expr7
;
/* mult and div */
expr7: expr7 TOKEN_MULT expr8
| expr7 TOKEN_DIV expr8
| expr7 TOKEN_MOD expr8
| expr8
;
/* Not (!) and unary minus and plus */
expr8: TOKEN_NOT val_literal
| TOKEN_NEG val_literal
| TOKEN_PLUS val_literal
| expr8 TOKEN_EXP val_literal
| val_literal
;
/* Highest precedence (Post increment (5++), function calls, array sub (a[5]), parenthesis grouping ((5*2) + 2))*/
val_literal : TOKEN_INT_LITERAL
| inc_or_dec
| TOKEN_CHAR_LITERAL
| TOKEN_FLOAT_LITERAL
| TOKEN_STRING_LITERAL
| TOKEN_TRUE
| TOKEN_FALSE
| func_call
| TOKEN_LPAREN expr TOKEN_RPAREN
| mut
;

inc_or_dec: TOKEN_IDENT TOKEN_INC
| TOKEN_IDENT TOKEN_DEC
;

mut : TOKEN_IDENT
| array_access
;

array_access : TOKEN_IDENT TOKEN_LBRACKET expr TOKEN_RBRACKET array_access_next

array_access_next : TOKEN_LBRACKET expr TOKEN_RBRACKET array_access_next
|
;

/* Array types (can be recursive) */
array_type : TOKEN_ARRAY TOKEN_LBRACKET array_size TOKEN_RBRACKET all_types
;

array_size : expr
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
