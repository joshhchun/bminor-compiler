#include "../include/gen_tokens.h"

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
        enum yytokentype t = yylex();
        switch (t) {
            case TOKEN_EOF:
                return EXIT_SUCCESS;
            case TOKEN_ARRAY:
                debug_print("ARRAY          %s\n", yytext);
                break;
            case TOKEN_AUTO:
                debug_print("AUTO           %s\n", yytext);
                break;
            case TOKEN_BOOL:
                debug_print("BOOL           %s\n", yytext);
                break;
            case TOKEN_CHAR:
                debug_print("CHAR           %s\n", yytext);
                break;
            case TOKEN_ELSE:
                debug_print("ELSE           %s\n", yytext);
                break;
            case TOKEN_FALSE:
                debug_print("FALSE          %s\n", yytext);
                break;
            case TOKEN_FLOAT:
                debug_print("FLOAT          %s\n", yytext);
                break;
            case TOKEN_FOR:
                debug_print("FOR            %s\n", yytext);
                break;
            case TOKEN_FUNC:
                debug_print("FOR            %s\n", yytext);
                break;
            case TOKEN_IF:
                debug_print("IF             %s\n", yytext);
                break;
            case TOKEN_INT:
                debug_print("INT            %s\n", yytext);
                break;
            case TOKEN_PRINT:
                debug_print("PRINT          %s\n", yytext);
                break;
            case TOKEN_RETURN:
                debug_print("RETURN         %s\n", yytext);
                break;
            case TOKEN_STR:
                debug_print("STRING         %s\n", yytext);
                break;
            case TOKEN_TRUE:
                debug_print("TRUE           %s\n", yytext);
                break;
            case TOKEN_VOID:
                debug_print("VOID           %s\n", yytext);
                break;
            case TOKEN_WHILE:
                debug_print("WHILE          %s\n", yytext);
                break;
            case TOKEN_ADD:
                debug_print("ADD            %s\n", yytext);
                break;
            case TOKEN_NEG:
                debug_print("NEGATIVE       %s\n", yytext);
                break;
            case TOKEN_MULT:
                debug_print("MULTIPLY       %s\n", yytext);
                break;
            case TOKEN_DIV:
                debug_print("DIVISION       %s\n", yytext);
                break;
            case TOKEN_MOD:
                debug_print("MODULO         %s\n", yytext);
                break;
            case TOKEN_EXP:
                debug_print("EXPONENT       %s\n", yytext);
                break;
            case TOKEN_LPAREN:
                debug_print("LEFT PAREN     %s\n", yytext);
                break;
            case TOKEN_RPAREN:
                debug_print("RIGHT PAREN    %s\n", yytext);
                break;
            case TOKEN_ASSIGN:
                debug_print("ASSIGN         %s\n", yytext);
                break;
            case TOKEN_LBRACE:
                debug_print("LEFT BRACE     %s\n", yytext);
                break;
            case TOKEN_RBRACE:
                debug_print("RIGHT BRACE    %s\n", yytext);
                break;
            case TOKEN_LBRACKET:
                debug_print("LEFT BRACKET   %s\n", yytext);
                break;
            case TOKEN_RBRACKET:
                debug_print("RIGHT BRACKET  %s\n", yytext);
                break;
            case TOKEN_INEQ:
                debug_print("INEQUALITY     %s\n", yytext);
                break;
            case TOKEN_EQ:
                debug_print("EQUALITY       %s\n", yytext);
                break;
            case TOKEN_NOT:
                debug_print("NOT            %s\n", yytext);
                break;
            case TOKEN_LT:
                debug_print("LESS THAN      %s\n", yytext);
                break;
            case TOKEN_GT:
                debug_print("GREATER THAN   %s\n", yytext);
                break;
            case TOKEN_AND:
                debug_print("AND            %s\n", yytext);
                break;
            case TOKEN_OR:
                debug_print("OR             %s\n", yytext);
                break;
            case TOKEN_DEFINE:
                debug_print("DEFINE         %s\n", yytext);
                break;
            case TOKEN_SEMICOLON:
                debug_print("SEMICOLON      %s\n", yytext);
                break;
            case TOKEN_COMMA:
                debug_print("COMMA          %s\n", yytext);
                break;
            case TOKEN_INC:
                debug_print("INCREMENT      %s\n", yytext);
                break;
            case TOKEN_DEC:
                debug_print("DECREMENT      %s\n", yytext);
                break;
            case TOKEN_COMMENT:
                debug_print("COMMENT        %s\n", yytext);
                break;
            case TOKEN_ERROR:
                debug_print("ERROR          %s\n", yytext);
                return EXIT_FAILURE;
                break;
            case TOKEN_LEQ:
                debug_print("LEQ            %s\n", yytext);
                break;
            case TOKEN_GEQ:
                debug_print("GEQ            %s\n", yytext);
                break;
            case TOKEN_IDENT:
                debug_print("IDENTIFIER     %s\n", yytext);
                break;
            case TOKEN_INT_LITERAL: {
                int64_t integer;
                if ((integer = atoi(yytext)) < 0) {
                    debug_print("ERROR: Integer too long\n");
                    return EXIT_FAILURE;
                }
                debug_print("INT LITERAL    %d\n", atoi(yytext));
            } break;
            case TOKEN_FLOAT_LITERAL:
                debug_print("FLOAT LITERAL  %lf\n", atof(yytext));
                break;
            case TOKEN_STRING_LITERAL: {
                char decoded[MAX_CHAR_LENGTH + 1] = {0};
                if (string_decode(yytext, decoded)) return EXIT_FAILURE;
                debug_print("STRING LITERAL %s\n", decoded);
            } break;
            case TOKEN_CHAR_LITERAL: {
                char c;
                if (!(c = decode_char(yytext))) {
                    debug_print("ERROR: Invalid char literal");
                    return EXIT_FAILURE;
                }
                debug_print("CHAR LITERAL   %s %c\n", yytext, c);
            } break;

            default:
                debug_print("Scan Error: %d is not a valid character.\n", t);
                return EXIT_FAILURE;
                break;
        }
    }
}
