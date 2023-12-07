#include "../include/encode.h"
/**
 *
 * Function to encode a string
 * Input: decoded string: const char*, encoded string: char *
 * Output: success status: int
 *
 */
#include <stdlib.h>
int string_encode(const char *s, char* es) {
    *es++ = '\"';
    for (; *s; s++, es++) {
        switch (*s) {
            case '\a':
                *es++ = '\\';
                *es = 'a';
                break;
            case '\b':
                *es++ = '\\';
                *es = 'b';
                break;
            case '\e':
                *es++ = '\\';
                *es = 'e';
                break;
            case '\f':
                *es++ = '\\';
                *es = 'f';
                break;
            case '\n':
                *es++ = '\\';
                *es = 'n';
                break;
            case '\r':
                *es++ = '\\';
                *es = 'r';
                break;
            case '\t':
                *es++ = '\\';
                *es = 't';
                break;
            case '\v':
                *es++ = '\\';
                *es = 'v';
                break;
            case '\\':
                *es++ = '\\';
                *es = '\\';
                break;
            case '\'':
                *es++ = '\\';
                *es = '\'';
                break;
            case '\"':
                *es++ = '\\';
                *es = '\"';
                break;
            default:
                *es = *s;
                break;
        }
    }
    *es = '\"';
    return 0;
}
#include <stdio.h>
/**
 *
 * Function to encode a char
 * Input: decoded char: char, encoded string: char*
 * Output: success status: int
 *
 */
char* char_encode(char c, char* es) {
    *es++ = '\'';
    switch (c) {
        case '\a':
            *es++ = '\\';
            *es = 'a';
            break;
        case '\b':
            *es++ = '\\';
            *es = 'b';
            break;
        case '\e':
            *es++ = '\\';
            *es = 'e';
            break;
        case '\f':
            *es++ = '\\';
            *es = 'f';
            break;
        case '\n':
            *es++ = '\\';
            *es = 'n';
            break;
        case '\r':
            *es++ = '\\';
            *es = 'r';
            break;
        case '\t':
            *es++ = '\\';
            *es = 't';
            break;
        case '\v':
            *es++ = '\\';
            *es = 'v';
            break;
        case '\\':
            *es++ = '\\';
            *es = '\\';
            break;
        case '\'':
            *es++ = '\\';
            *es = '\'';
            break;
        case '\"':
            *es++ = '\\';
            *es = '\"';
            break;
        default: {
            char hex_str[10] = {0};
            sprintf(hex_str, "0x%X", (uint8_t)c);
            strcpy(es, hex_str);
            es += 3;
            break;
        }
    }
    *(++es) = '\'';
    return 0;
}

