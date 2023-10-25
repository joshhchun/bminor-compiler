#include "encode.h"
#include "gen_tokens.h"

#define MAX_CHAR_LENGTH 255
#define same_str(s1, s2) (!strcmp(s1, s2) ? 1 : 0)
#define file_open(f, m) { \
            FILE *fp; \
            if (!(fp = fopen(f, m))) { \
                fprintf(stderr, "ERROR: Could not open file %s in mode %m.\n", f, m); \
                exit(1); \
            } \
        } \

