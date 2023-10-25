#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 *
 * Function to decode a string
 * Input: encoded string: const char*, decoded string: char *
 * Output: success status: int
 *
 */
int string_decode(const char *es, char *s) {
    const char *end_ptr = es + strlen(es) - 1;
    /* Check if string is surrounded by quotations */
    if (*es && (es == end_ptr || *es++ != '\"' || *end_ptr != '\"')) {
        fprintf(stderr, "ERROR: String not surrounded by quotations\n");
        return 1;
    }

    for (; es < end_ptr; es++, s++) {
        /* Backslash code, need to check next char(s) */
        if (*es == '\\') {
            switch (*++es) {
                case 'a':
                    *s = '\a';
                    break;
                case 'b':
                    *s = '\b';
                    break;
                case 'e':
                    *s = '\e';
                    break;
                case 'f':
                    *s = '\f';
                    break;
                case 'n':
                    *s = '\n';
                    break;
                case 'r':
                    *s = '\r';
                    break;
                case 't':
                    *s = '\t';
                    break;
                case 'v':
                    *s = '\v';
                    break;
                case '\\':
                    *s = '\\';
                    break;
                case '\'':
                    *s = '\'';
                    break;
                case '\"':
                    if (es == end_ptr) {
                        fprintf(stderr, "ERROR: Invalid backslash at end of string\n");
                        return 1;
                    }
                    *s = '\"';
                    break;
                case '0':
                    if (strlen(es) < 5 || *(es + 1) != 'x') {
                        fprintf(stderr, "ERROR: Invalid hexadecimal backslash code\n");
                        return 1;
                    }
                    char* hex_end_ptr = NULL;
                    char hex_values[3] = {*(es + 2), *(es + 3), '\0'};
                    *s = (char)strtol(hex_values, &hex_end_ptr, 16);
                    if (*hex_end_ptr) {
                        fprintf(stderr, "ERROR: Invalid hexadecimal backslash code: 0x%s\n", hex_values);
                        return 1;
                    }
                    es += 3;
                    break;
                default:
                    fprintf(stderr, "ERROR: Invalid backslash code: \\%c\n", *es);
                    return 1;
            }
        } else {
            if (*es == '\"' && es != end_ptr) {
                fprintf(stderr, "ERROR: Invalid quote in middle of string\n");
                return 1;
            }
            *s = *es;
        }
    }
    return 0;
}
