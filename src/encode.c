/**
 *
 * Function to encode a string
 * Input: decoded string: const char*, encoded string: char *
 * Output: success status: int
 *
 */
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

