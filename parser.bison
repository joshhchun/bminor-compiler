%{
#include <stdio.h>
#include "../include/decl.h"

extern char *yytext;
extern int yylex();
extern int yyerror( char *str );
struct decl* parser_result = 0;
%}

%token TOKEN_INT
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

%union {
        char* string_literal;
        int int_literal;
        char* char_literal;

        struct decl *decl;
        struct stmt *stmt;
        struct expr *expr;
        struct param_list* param_list;
        struct type *type;
}

%type <decl> program decl decl_list func_decl var_decl

%type <param_list> param_list param_next

%type <expr> expr expr2 expr3 expr4 expr5 expr6 expr7 expr8 expr_list opt_expr_list mut inc_or_dec expr_assign func_call if_expr for_expr ident_expr val_literal array_access array_size

%type <stmt> stmt stmt_list for_stmt cmpd_stmt simp_stmt if_dangle reg_end dangle_end for_cond stmt_next

%type <type> val_type all_types array_type return_type 

%type <string_literal> ident


%%
program : decl_list TOKEN_EOF { parser_result = $1; return 0;}
| TOKEN_EOF { parser_result = 0; return 0;}
;

/*  Decl list (highest level thing)*/
decl_list : decl decl_list
{
        $1->next = $2;
        $$ = $1;
}
| decl { $$ = $1; }
;

/* Variable decls and Function decls */
decl : var_decl { $$ = $1; }
| func_decl { $$ = $1; }
;

/* Variable declarations */
var_decl:
/* To declare a normal variable with a type (stmts)*/
ident TOKEN_DEFINE val_type init expr TOKEN_SEMICOLON { $$ = decl_create($1, $3, $5, 0, 0); }
| ident TOKEN_DEFINE val_type TOKEN_SEMICOLON         { $$ = decl_create($1, $3, 0, 0, 0); }
/*  Array decl */
| ident TOKEN_DEFINE array_type init expr TOKEN_SEMICOLON { $$ = decl_create($1, $3, $5, 0, 0); }
/*  Array */
| ident TOKEN_DEFINE array_type TOKEN_SEMICOLON { $$ = decl_create($1, $3, 0, 0, 0); }
;

/* Function declarations */
func_decl: 
/*  Func prototype */
ident TOKEN_DEFINE TOKEN_FUNC return_type TOKEN_LPAREN param_list TOKEN_RPAREN TOKEN_SEMICOLON { $$ = decl_create($1, type_create(TYPE_FUNC, $4, $6), 0, 0, 0); }
/*  Func assignment */
| ident TOKEN_DEFINE TOKEN_FUNC return_type TOKEN_LPAREN param_list TOKEN_RPAREN init TOKEN_LBRACE stmt_list TOKEN_RBRACE { $$ = decl_create($1, type_create(TYPE_FUNC, $4, $6), 0, $10, 0); }
;

/* Statement lists */
stmt_list : stmt stmt_next
{
        $1->next = $2;
        $$ = stmt_create(STMT_BLOCK, 0, 0, 0, 0, $1, 0, 0);
}
| { $$ = stmt_create(STMT_BLOCK, 0, 0, 0, 0, 0, 0, 0); }
;

stmt_next: stmt stmt_next { $1->next = $2; }
| { $$ = 0; }
;

/* Statements (make up decls) */
stmt: simp_stmt { $$ = $1; }
| cmpd_stmt { $$ = $1; }
;

/* Non right recursive statements */
simp_stmt : TOKEN_LBRACE stmt_list TOKEN_RBRACE { $$ = $2; } 
| var_decl                                  { $$ = stmt_create(STMT_DECL, $1, 0, 0, 0, 0, 0, 0); }
| TOKEN_RETURN expr TOKEN_SEMICOLON         { $$ = stmt_create(STMT_RETURN, 0, 0, $2, 0, 0, 0, 0); }
| TOKEN_RETURN TOKEN_SEMICOLON              { $$ = stmt_create(STMT_RETURN, 0, 0, 0, 0, 0, 0, 0); }
| TOKEN_PRINT opt_expr_list TOKEN_SEMICOLON { $$ = stmt_create(STMT_PRINT, 0, 0, $2, 0, 0, 0, 0); }
| inc_or_dec TOKEN_SEMICOLON                { $$ = stmt_create(STMT_EXPR, 0, 0, $1, 0, 0, 0, 0); }
| expr_assign TOKEN_SEMICOLON               { $$ = stmt_create(STMT_EXPR, 0, 0, $1, 0, 0, 0, 0); }
| func_call TOKEN_SEMICOLON                 { $$ = stmt_create(STMT_EXPR, 0, 0, $1, 0, 0, 0, 0); }
;

/* If and for statements */
cmpd_stmt : if_expr stmt                    { $$ = stmt_create(STMT_IF_ELSE, 0, 0, $1, 0, $2, 0, 0); }
| if_expr if_dangle TOKEN_ELSE stmt 
{
        $$ = stmt_create(STMT_IF_ELSE, 0, 0, $1, 0, $2, $4, 0);
}
| for_stmt reg_end 
{ 
        $1->body = $2;
        $$ = $1;
}
;

/* Non dangling if statement */
if_dangle: if_expr if_dangle TOKEN_ELSE if_dangle
{
        $$ = stmt_create(STMT_IF_ELSE, 0, 0, $1, 0, $2, $4, 0);
}
| for_stmt dangle_end { $1->body = $2; }
| simp_stmt { $$ = $1; }
;

/* If statement expression condition */
if_expr: TOKEN_IF TOKEN_LPAREN expr TOKEN_RPAREN  { $$ = $3; } 
;

/* For loop statement */
for_stmt: TOKEN_FOR for_cond { $$ = $2; }
;
for_cond: TOKEN_LPAREN for_expr TOKEN_SEMICOLON for_expr TOKEN_SEMICOLON for_expr TOKEN_RPAREN {$$ = stmt_create(STMT_FOR, 0, $2, $4, $6, 0, 0, 0);}
;
for_expr: expr { $$ = $1; }
| { $$ = 0; }
;

/* For loop end if non dangling if statement */
dangle_end: TOKEN_SEMICOLON { $$ = 0; }
| if_dangle { $$ = $1; }
;

/* For loop end if regular if statement */
reg_end: TOKEN_SEMICOLON { $$ = 0; }
| stmt { $$ = $1; }
;

/* Calling a function */
func_call: ident_expr TOKEN_LPAREN opt_expr_list TOKEN_RPAREN { $$ = expr_create(EXPR_FUNC, $1, $3); }
;

/* Expression list (func calls, print, etc.) */
expr_list : expr { $$ = expr_create(EXPR_ARG, $1, 0); }
| expr TOKEN_COMMA expr_list
{ 
        $$ = expr_create(EXPR_ARG, $1, $3);
}
;

/* Optional expression list (can be empty) */
opt_expr_list : expr_list { $$ = $1; }
| { $$ = 0; } 
;

/*  Expressions */
/*  Assignment expressions */
expr_assign: mut init expr { $$ = expr_create(EXPR_ASSIGN, $1, $3); }
;
/* Expressions in order of lowest precedence to highest */
/* assign */
expr : expr_assign { $$ = $1; }
| expr2 { $$ = $1; }
;
/* logical or */
expr2: expr2 TOKEN_OR expr3 { $$ = expr_create(EXPR_OR, $1, $3); }
| expr3 { $$ = $1; }
;
/* logical and */
expr3: expr3 TOKEN_AND expr4 { $$ = expr_create(EXPR_AND, $1, $3); }
| expr4 { $$ = $1; }
;
/* equality */
expr4: expr4 TOKEN_EQ expr5 { $$ = expr_create(EXPR_EQ, $1, $3); }
| expr4 TOKEN_NOT TOKEN_EQ expr5 { $$ = expr_create(EXPR_NEQ, $1, $4); }
| expr5 { $$ = $1; }
;
/* equalities */
expr5: expr5 TOKEN_LT expr6 { $$ = expr_create(EXPR_LT, $1, $3); }
| expr5 TOKEN_GT expr6      { $$ = expr_create(EXPR_GT, $1, $3); }
| expr5 TOKEN_LEQ expr6     { $$ = expr_create(EXPR_LEQ, $1, $3); }
| expr5 TOKEN_GEQ expr6     { $$ = expr_create(EXPR_GEQ, $1, $3); }
| expr6 { $$ = $1; }
;
/* addition and subtraction */
expr6: expr6 TOKEN_ADD expr7 { $$ = expr_create(EXPR_ADD, $1, $3); }
| expr6 TOKEN_NEG expr7 { $$ = expr_create(EXPR_NEG, $1, $3); }
| expr7 { $$ = $1; }
;
/* mult and div */
expr7: expr7 TOKEN_MULT expr8 { $$ = expr_create(EXPR_MULT, $1, $3); }
| expr7 TOKEN_DIV expr8 { $$ = expr_create(EXPR_DIV, $1, $3); }
| expr7 TOKEN_MOD expr8 { $$ = expr_create(EXPR_MOD, $1, $3); }
| expr8 { $$ = $1; }
;
/* Not (!) and unary minus and plus */
expr8: TOKEN_NOT val_literal  { $$ = expr_create(EXPR_NOT, $2, 0); }
| TOKEN_NEG val_literal       { $$ = expr_create(EXPR_NEG, $2, 0); }
| TOKEN_ADD val_literal      { $$ = expr_create(EXPR_PLUS, $2, 0); }
| expr8 TOKEN_EXP val_literal { $$ = expr_create(EXPR_EXP, $1, $3); }
| TOKEN_LBRACE expr_list TOKEN_RBRACE { $$ = expr_create(EXPR_ARRAY_INIT, $2, 0); }
| val_literal { $$ = $1; }
;
/* Highest precedence (Post increment (5++), function calls, array sub (a[5]), parenthesis grouping ((5*2) + 2))*/
val_literal : TOKEN_INT_LITERAL { $$ = expr_create_integer_literal(atoi(yytext)); }
| inc_or_dec { $$ = $1; }
| TOKEN_CHAR_LITERAL
{ 
        $$ = expr_create_char_literal(yytext);
}
| TOKEN_FLOAT_LITERAL { $$ = expr_create_float_literal(atof(yytext)); }
| TOKEN_STRING_LITERAL { $$ = expr_create_string_literal(yytext); }
| TOKEN_TRUE { $$ = expr_create_bool_literal(1); }
| TOKEN_FALSE { $$ = expr_create_bool_literal(0); }
| func_call { $$ = $1; }
| TOKEN_LPAREN expr TOKEN_RPAREN { $$ = expr_create(EXPR_PAREN, 0, $2); }
| mut { $$ = $1; }
;

inc_or_dec: ident_expr TOKEN_INC { $$ = expr_create(EXPR_INC, $1, 0); }
| ident_expr TOKEN_DEC           { $$ = expr_create(EXPR_DEC, $1, 0); }
;

ident: TOKEN_IDENT
{ 
        char *s;
        if (!(s = strdup(yytext))) {
                fprintf(stderr, "ERROR: Could not allocate enough space for ident.\n");
                exit(EXIT_FAILURE);
        }
        $$ = s;
}
;

mut : ident_expr { $$ = $1; }
| ident_expr array_access { $$ = expr_create(EXPR_ARRAY_SUB, $1, $2); }
;

ident_expr : ident { $$ = expr_create_ident($1); }
;

array_access : TOKEN_LBRACKET expr TOKEN_RBRACKET array_access { $$ = expr_create(EXPR_ARG, $2, $4); }
| TOKEN_LBRACKET expr TOKEN_RBRACKET { $$ = expr_create(EXPR_ARG, $2, 0); }
;

/* Array types (can be recursive) */
array_type : TOKEN_ARRAY TOKEN_LBRACKET array_size TOKEN_RBRACKET all_types
           { 
                $$ = type_create(TYPE_ARRAY, $5, 0);
                $$->array_size = $3;
           }
;

array_size : expr { $$ = $1; }
| { $$ = 0; }
;

all_types: val_type { $$ = $1; }
| array_type { $$ = $1; }
;

val_type : TOKEN_INT { $$ = type_create(TYPE_INT, 0, 0); }
| TOKEN_FLOAT  { $$ = type_create(TYPE_FLOAT, 0, 0); }
| TOKEN_BOOL { $$ = type_create(TYPE_BOOL, 0, 0); }
| TOKEN_CHAR { $$ = type_create(TYPE_CHAR, 0, 0); }
| TOKEN_STR { $$ = type_create(TYPE_STR, 0, 0); }
;

/* Function return types */
return_type : val_type { $$ = $1; }
| TOKEN_VOID { $$ = type_create(TYPE_VOID, 0, 0); }
;

/* Param lists (when declaring function) */
param_list : ident TOKEN_DEFINE all_types param_next { $$ = param_list_create($1, $3, $4); }
| { $$ = 0; }
;
param_next : TOKEN_COMMA ident TOKEN_DEFINE all_types param_next { $$ = param_list_create($2, $4, $5); }
| { $$ = 0; }
;

init: TOKEN_ASSIGN
;

%%

int yyerror(char *s) {
    printf("parse error: %s\n",s);
    return 1;
}
