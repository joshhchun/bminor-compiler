#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "token.h"
#include "decode.c"

#define MAX_CHAR_LENGTH 255

extern FILE *yyin;
extern int yylex();
extern char *yytext;

/**
 *
 * Function to decode a singular char
 * Input: encoded char: char*
 * Output: decoded char: char
 *
 */
char decode_char(char* c) {
    size_t len = strlen(c);

    /* Singular char, return it */
    if (len == 3) return c[1];
    c += 2;

    /* Special backslash code */
    if (len == 4) {
        switch (*c) {
            case 'a':
                return '\a';
            case 'b':
                return '\b';
            case 'e':
                return '\e';
            case 'f':
                return '\f';
            case 'n':
                return '\n';
            case 'r':
                return '\r';
            case 't':
                return '\t';
            case 'v':
                return '\v';
            case '\\':
                return '\\';
            case '\'':
                return '\'';
            default:
                return '\0';
        }
    }

    /* Hex code */    
    char hex_values[3] = {*(c + 2), *(c + 3), '\0'};
    return (char)strtol(hex_values, NULL, 16);
}

/**
 *
 * Function to scan through source file and generate tokens using Flex.
 * Input: void
 * Output: success status: int
 *
 */
int scanner() {
    while(1) {
        token_t t = yylex();
        switch (t) {
            case TOKEN_EOF:
                return EXIT_SUCCESS;
            case TOKEN_ARRAY:
                printf("ARRAY          %s\n", yytext);
                break;
            case TOKEN_AUTO:
                printf("AUTO           %s\n", yytext);
                break;
            case TOKEN_BOOL:
                printf("BOOL           %s\n", yytext);
                break;
            case TOKEN_CHAR:
                printf("CHAR           %s\n", yytext);
                break;
            case TOKEN_ELSE:
                printf("ELSE           %s\n", yytext);
                break;
            case TOKEN_FALSE:
                printf("FALSE          %s\n", yytext);
                break;
            case TOKEN_FLOAT:
                printf("FLOAT          %s\n", yytext);
                break;
            case TOKEN_FOR:
                printf("FOR            %s\n", yytext);
                break;
            case TOKEN_FUNC:
                printf("FOR            %s\n", yytext);
                break;
            case TOKEN_IF:
                printf("IF             %s\n", yytext);
                break;
            case TOKEN_INT:
                printf("INT            %s\n", yytext);
                break;
            case TOKEN_PRINT:
                printf("PRINT          %s\n", yytext);
                break;
            case TOKEN_RETURN:
                printf("RETURN         %s\n", yytext);
                break;
            case TOKEN_STR:
                printf("STRING         %s\n", yytext);
                break;
            case TOKEN_TRUE:
                printf("TRUE           %s\n", yytext);
                break;
            case TOKEN_VOID:
                printf("VOID           %s\n", yytext);
                break;
            case TOKEN_WHILE:
                printf("WHILE          %s\n", yytext);
                break;
            case TOKEN_ADD:
                printf("ADD            %s\n", yytext);
                break;
            case TOKEN_NEG:
                printf("NEGATIVE       %s\n", yytext);
                break;
            case TOKEN_MULT:
                printf("MULTIPLY       %s\n", yytext);
                break;
            case TOKEN_DIV:
                printf("DIVISION       %s\n", yytext);
                break;
            case TOKEN_MOD:
                printf("MODULO         %s\n", yytext);
                break;
            case TOKEN_EXP:
                printf("EXPONENT       %s\n", yytext);
                break;
            case TOKEN_LPAREN:
                printf("LEFT PAREN     %s\n", yytext);
                break;
            case TOKEN_RPAREN:
                printf("RIGHT PAREN    %s\n", yytext);
                break;
            case TOKEN_ASSIGN:
                printf("ASSIGN         %s\n", yytext);
                break;
            case TOKEN_LBRACE:
                printf("LEFT BRACE     %s\n", yytext);
                break;
            case TOKEN_RBRACE:
                printf("RIGHT BRACE    %s\n", yytext);
                break;
            case TOKEN_LBRACKET:
                printf("LEFT BRACKET   %s\n", yytext);
                break;
            case TOKEN_RBRACKET:
                printf("RIGHT BRACKET  %s\n", yytext);
                break;
            case TOKEN_INEQ:
                printf("INEQUALITY     %s\n", yytext);
                break;
            case TOKEN_EQ:
                printf("EQUALITY       %s\n", yytext);
                break;
            case TOKEN_NOT:
                printf("NOT            %s\n", yytext);
                break;
            case TOKEN_LT:
                printf("LESS THAN      %s\n", yytext);
                break;
            case TOKEN_GT:
                printf("GREATER THAN   %s\n", yytext);
                break;
            case TOKEN_AND:
                printf("AND            %s\n", yytext);
                break;
            case TOKEN_OR:
                printf("OR             %s\n", yytext);
                break;
            case TOKEN_DEFINE:
                printf("DEFINE         %s\n", yytext);
                break;
            case TOKEN_SEMICOLON:
                printf("SEMICOLON      %s\n", yytext);
                break;
            case TOKEN_COMMA:
                printf("COMMA          %s\n", yytext);
                break;
            case TOKEN_INC:
                printf("INCREMENT      %s\n", yytext);
                break;
            case TOKEN_DEC:
                printf("DECREMENT      %s\n", yytext);
                break;
            case TOKEN_COMMENT:
                printf("COMMENT        %s\n", yytext);
                break;
            case TOKEN_ERROR:
                printf("ERROR          %s\n", yytext);
                return EXIT_FAILURE;
                break;
            case TOKEN_LEQ:
                printf("LEQ            %s\n", yytext);
                break;
            case TOKEN_GEQ:
                printf("GEQ            %s\n", yytext);
                break;
            case TOKEN_IDENT:
                printf("IDENTIFIER     %s\n", yytext);
                break;
            case TOKEN_INT_LITERAL: {
                int64_t integer;
                if ((integer = atoi(yytext)) < 0) {
                    fprintf(stderr, "ERROR: Integer too long\n");
                    return EXIT_FAILURE;
                }
                printf("INT LITERAL    %d\n", atoi(yytext));
            } break;
            case TOKEN_FLOAT_LITERAL:
                printf("FLOAT LITERAL  %lf\n", atof(yytext));
                break;
            case TOKEN_STRING_LITERAL: {
                char decoded[MAX_CHAR_LENGTH + 1] = {0};
                if (string_decode(yytext, decoded)) return EXIT_FAILURE;
                printf("STRING LITERAL %s\n", decoded);
            } break;
            case TOKEN_CHAR_LITERAL: {
                char c;
                if (!(c = decode_char(yytext))) {
                    fprintf(stderr, "ERROR: Invalid char literal");
                    return EXIT_FAILURE;
                }
                printf("CHAR LITERAL   %s %c\n", yytext, c);
            } break;

            default:
                printf("Scan Error: %d is not a valid character.\n", t);
                return EXIT_FAILURE;
                break;
        }
    }
}
