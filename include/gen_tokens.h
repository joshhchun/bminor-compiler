#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "token.h"
#include "decode.h"

extern FILE *yyin;
extern int yylex();
extern char *yytext;
extern int yyparse();
extern int yyerror(char *s);
extern int DEBUG;
int scanner();

#define MAX_CHAR_LENGTH 255
#define debug_print(...) \
            do { if (DEBUG) printf(__VA_ARGS__); } while (0)
