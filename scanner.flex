%{
#include "../include/token.h"
#include "../include/decode.h"
%}

DIGIT    [0-9]
LETTER   [a-zA-Z]
HEX      [0-9a-fA-F]

%%
(" "|\t|\n|\r)+                                       { /* ignore white space */ }


array                                                 { return TOKEN_ARRAY; }
auto                                                  { return TOKEN_AUTO; }
boolean                                               { return TOKEN_BOOL; }
char                                                  { return TOKEN_CHAR; }
else                                                  { return TOKEN_ELSE; }
false                                                 { return TOKEN_FALSE; }
float                                                 { return TOKEN_FLOAT; }
for                                                   { return TOKEN_FOR; }
function                                              { return TOKEN_FUNC; }
if                                                    { return TOKEN_IF; }
integer                                               { return TOKEN_INT; }
print                                                 { return TOKEN_PRINT; }
return                                                { return TOKEN_RETURN; }
string                                                { return TOKEN_STR; }
true                                                  { return TOKEN_TRUE; }
void                                                  { return TOKEN_VOID; }
while                                                 { return TOKEN_WHILE; }

\(                                                    { return TOKEN_LPAREN; }
\)                                                    { return TOKEN_RPAREN; }
\{                                                    { return TOKEN_LBRACE; }
\}                                                    { return TOKEN_RBRACE; }
\[                                                    { return TOKEN_LBRACKET; }
\]                                                    { return TOKEN_RBRACKET; }
\,                                                    { return TOKEN_COMMA; }
\+\+                                                  { return TOKEN_INC; }
\-\-                                                  { return TOKEN_DEC; }
\+                                                    { return TOKEN_ADD; }
\-                                                    { return TOKEN_NEG; }
\*                                                    { return TOKEN_MULT; }
\/                                                    { return TOKEN_DIV; }
%                                                     { return TOKEN_MOD; }
=                                                     { return TOKEN_ASSIGN; }
\^                                                    { return TOKEN_EXP; }
!=                                                    { return TOKEN_INEQ; }
==                                                    { return TOKEN_EQ; }
!                                                     { return TOKEN_NOT; }
\<                                                    { return TOKEN_LT; }
\>                                                    { return TOKEN_GT; }
\<=                                                   { return TOKEN_LEQ; }
\>=                                                   { return TOKEN_GEQ; }
&&                                                    { return TOKEN_AND; }
\|\|                                                  { return TOKEN_OR; }
\:                                                    { return TOKEN_DEFINE; }
\;                                                    { return TOKEN_SEMICOLON; }
({LETTER}|_)({DIGIT}|{LETTER}|_)*                     { 
                                                        if (strlen(yytext) > 255) {
                                                            return TOKEN_ERROR;
                                                        } 
                                                        char *s = strdup(yytext);
                                                        yylval.string_literal = s;
                                                        return TOKEN_IDENT;
                                                      }
{DIGIT}+                                              { return TOKEN_INT_LITERAL; }
({DIGIT}+(\.{DIGIT}*|((\.{DIGIT}+)?[eE][-+]?{DIGIT}+))|\.{DIGIT}+) { return TOKEN_FLOAT_LITERAL; }
\"([^"\\\n]|\\.){0,255}\"                             { return TOKEN_STRING_LITERAL; }
'([^\\']|\\[^']|(\\0x{HEX}{HEX}))'                    { 
                                                        uint8_t y = decode_char(yytext);
                                                        yylval.char_literal = y;
                                                        return TOKEN_CHAR_LITERAL;
                                                      }

(\/\*([^*]|\*[^\/])*\*\/)|(\/\*([^\*]|\*[^\/])*\*\*\/)                { /* Ignore */ }
\/\/[^\n]*\n                                          { /* Ignore */ }                                
<<EOF>>                                               { return TOKEN_EOF; }
.                                                     { return TOKEN_ERROR; }

%%
int yywrap() { return 1; }
