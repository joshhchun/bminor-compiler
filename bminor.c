#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR_LENGTH 255
#define same_str(s1, s2) (!strcmp(s1, s2) ? 1 : 0)


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
    if (*es && (*es++ != '\"' || *end_ptr != '\"')) {
        fprintf(stderr, "ERROR: String not surrounded by quotations\n");
        return 1;
    }

    for (; es < end_ptr; es++ && s++) {
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

/**
 *
 * Function to encode a string
 * Input: decoded string: const char*, encoded string: char *
 * Output: success status: int
 *
 */
int string_encode(const char *s, char* es) {
    *es++ = '\"';
    for (; *s; s++ && es++) {
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


/**
 *
 * Usage helper
 * Input:  program name: const char*, exit code status: int
 * Output: void
 *
 */
void usage(const char* program_name, int status) {
    fprintf(stderr, "Usage: %s [options] file_name\n", program_name);
    fprintf(stderr, "\t--encode : Encode string if valid\n");
    exit(status);
}

/**
 *
 * Function to read in the first line of a file
 * Input:  file name: const char*, encoded line: char *
 * Output: success status: int
 *
 */
int read_input(const char* file_name, char* encoded_line) {
    FILE* fp = fopen(file_name, "r");
    if (!fp) {
        fprintf(stderr, "ERROR: Unable to open file: %s\n", file_name);
        return 1;
    }
    if (!(fgets(encoded_line, BUFSIZ, fp))) {
        fprintf(stderr, "ERROR: Could not read from file: %s\n", file_name);
        fclose(fp);
        return 1;
    }

    if (strlen(encoded_line) > MAX_CHAR_LENGTH) {
        fprintf(stderr, "ERROR: String length exceeds maximum value of 255.\n");
        fclose(fp);
        return 1;
    }
    
    return 0;
}

int main(int argc, char** argv) {
    /* Usage */
    if (argc != 3) usage(argv[0], 1);
    if (same_str(argv[1], "--help")) usage(argv[0], 0);
    if (!same_str(argv[1], "--encode")) return 0;

    /* Read in encoded line */
    char encoded_line[MAX_CHAR_LENGTH + 1] = {0};
    if (read_input(argv[2], encoded_line)) return 1;

    /* Decode line */
    char decoded_line[MAX_CHAR_LENGTH + 1] = {0};
    if (string_decode((const char *)encoded_line, decoded_line)) return 1;
    
    /* Clear the encoded line */
    char* end_ptr = encoded_line + strlen(encoded_line);
    for (char *p = encoded_line; (*p = 0) || p < end_ptr; ++p);
    
    /* Encode the line */
    if (string_encode((const char*)decoded_line, encoded_line)) return 1;
    fprintf(stdout, "Decoded line: %s\n", decoded_line);
    fprintf(stdout, "Encoded line: %s\n", encoded_line);

    return 0;
}


