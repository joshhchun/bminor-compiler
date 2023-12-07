#include "../include/gen_tokens.h"

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
                scan_print("ARRAY          %s\n", yytext);
                break;
            case TOKEN_AUTO:
                scan_print("AUTO           %s\n", yytext);
                break;
            case TOKEN_BOOL:
                scan_print("BOOL           %s\n", yytext);
                break;
            case TOKEN_CHAR:
                scan_print("CHAR           %s\n", yytext);
                break;
            case TOKEN_ELSE:
                scan_print("ELSE           %s\n", yytext);
                break;
            case TOKEN_FALSE:
                scan_print("FALSE          %s\n", yytext);
                break;
            case TOKEN_FLOAT:
                scan_print("FLOAT          %s\n", yytext);
                break;
            case TOKEN_FOR:
                scan_print("FOR            %s\n", yytext);
                break;
            case TOKEN_FUNC:
                scan_print("FOR            %s\n", yytext);
                break;
            case TOKEN_IF:
                scan_print("IF             %s\n", yytext);
                break;
            case TOKEN_INT:
                scan_print("INT            %s\n", yytext);
                break;
            case TOKEN_PRINT:
                scan_print("PRINT          %s\n", yytext);
                break;
            case TOKEN_RETURN:
                scan_print("RETURN         %s\n", yytext);
                break;
            case TOKEN_STR:
                scan_print("STRING         %s\n", yytext);
                break;
            case TOKEN_TRUE:
                scan_print("TRUE           %s\n", yytext);
                break;
            case TOKEN_VOID:
                scan_print("VOID           %s\n", yytext);
                break;
            case TOKEN_WHILE:
                scan_print("WHILE          %s\n", yytext);
                break;
            case TOKEN_ADD:
                scan_print("ADD            %s\n", yytext);
                break;
            case TOKEN_NEG:
                scan_print("NEGATIVE       %s\n", yytext);
                break;
            case TOKEN_MULT:
                scan_print("MULTIPLY       %s\n", yytext);
                break;
            case TOKEN_DIV:
                scan_print("DIVISION       %s\n", yytext);
                break;
            case TOKEN_MOD:
                scan_print("MODULO         %s\n", yytext);
                break;
            case TOKEN_EXP:
                scan_print("EXPONENT       %s\n", yytext);
                break;
            case TOKEN_LPAREN:
                scan_print("LEFT PAREN     %s\n", yytext);
                break;
            case TOKEN_RPAREN:
                scan_print("RIGHT PAREN    %s\n", yytext);
                break;
            case TOKEN_ASSIGN:
                scan_print("ASSIGN         %s\n", yytext);
                break;
            case TOKEN_LBRACE:
                scan_print("LEFT BRACE     %s\n", yytext);
                break;
            case TOKEN_RBRACE:
                scan_print("RIGHT BRACE    %s\n", yytext);
                break;
            case TOKEN_LBRACKET:
                scan_print("LEFT BRACKET   %s\n", yytext);
                break;
            case TOKEN_RBRACKET:
                scan_print("RIGHT BRACKET  %s\n", yytext);
                break;
            case TOKEN_INEQ:
                scan_print("INEQUALITY     %s\n", yytext);
                break;
            case TOKEN_EQ:
                scan_print("EQUALITY       %s\n", yytext);
                break;
            case TOKEN_NOT:
                scan_print("NOT            %s\n", yytext);
                break;
            case TOKEN_LT:
                scan_print("LESS THAN      %s\n", yytext);
                break;
            case TOKEN_GT:
                scan_print("GREATER THAN   %s\n", yytext);
                break;
            case TOKEN_AND:
                scan_print("AND            %s\n", yytext);
                break;
            case TOKEN_OR:
                scan_print("OR             %s\n", yytext);
                break;
            case TOKEN_DEFINE:
                scan_print("DEFINE         %s\n", yytext);
                break;
            case TOKEN_SEMICOLON:
                scan_print("SEMICOLON      %s\n", yytext);
                break;
            case TOKEN_COMMA:
                scan_print("COMMA          %s\n", yytext);
                break;
            case TOKEN_INC:
                scan_print("INCREMENT      %s\n", yytext);
                break;
            case TOKEN_DEC:
                scan_print("DECREMENT      %s\n", yytext);
                break;
            case TOKEN_COMMENT:
                scan_print("COMMENT        %s\n", yytext);
                break;
            case TOKEN_ERROR:
                fprintf(stderr, "Scan Error: %s is not a valid character.\n", yytext);
                return EXIT_FAILURE;
                break;
            case TOKEN_LEQ:
                scan_print("LEQ            %s\n", yytext);
                break;
            case TOKEN_GEQ:
                scan_print("GEQ            %s\n", yytext);
                break;
            case TOKEN_IDENT:
                scan_print("IDENTIFIER     %s\n", yytext);
                break;
            case TOKEN_INT_LITERAL: {
                int64_t integer;
                if ((integer = atoi(yytext)) < 0) {
                    scan_print("ERROR: Integer too long\n");
                    return EXIT_FAILURE;
                }
                scan_print("INT LITERAL    %d\n", atoi(yytext));
            } break;
            case TOKEN_FLOAT_LITERAL:
                scan_print("FLOAT LITERAL  %lf\n", atof(yytext));
                break;
            case TOKEN_STRING_LITERAL: {
                char decoded[MAX_CHAR_LENGTH + 1] = {0};
                if (string_decode(yytext, decoded)) return EXIT_FAILURE;
                scan_print("STRING LITERAL %s\n", decoded);
            } break;
            case TOKEN_CHAR_LITERAL: {
                char c;
                if (!(c = decode_char(yytext))) {
                    scan_print("ERROR: Invalid char literal");
                    return EXIT_FAILURE;
                }
                scan_print("CHAR LITERAL   %s %c\n", yytext, c);
            } break;

            default:
                fprintf(stderr, "Scan Error: %d is not a valid character.\n", t);
                return EXIT_FAILURE;
                break;
        }
    }
}
