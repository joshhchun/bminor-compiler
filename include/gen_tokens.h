#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "token.h"
#include "decode.h"


typedef enum p_type {
    T_SCAN,
    T_PARSE,
    T_PRINT,
    T_RESOLVE,
} p_type;

extern p_type PROGRAM_TYPE;
extern FILE *yyin;
extern int yylex();
extern char *yytext;
extern int yyparse();
extern int yyerror(char *s);
int scanner();

#define MAX_CHAR_LENGTH 255
#define scan_print(...) \
            do { \
                if (PROGRAM_TYPE == T_SCAN) printf(__VA_ARGS__); \
            } while (0)
