#include "../include/bminor.h"

int DEBUG = 0;

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
    fprintf(stderr, "\t--scan   : Scan a file and print out tokens\n");
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

void scan(const char* file_name) {
    if (!(yyin = fopen(file_name, "r"))) {
        printf("Could not open %s\n", file_name);
        exit(1);
    };
    if (scanner()) { 
        printf("Program did not scan successfully.\n");
        exit(1);
    } else printf("Program scanned successfully.\n");
    fclose(yyin);
}

void parse(const char* file_name) {
        if (!(yyin = fopen(file_name, "r"))) {
            printf("Could not open %s\n", file_name);
            exit(1);
        };
        if (yyparse()) {
            printf("Program did not parse successfully.\n");
            exit(1);
        } else printf("Program parsed successfully.\n");
        fclose(yyin);
}

void pprint(const char* file_name, struct decl* parser_result) {
    printf("%s\n", parser_result->ident);
}

int main(int argc, char** argv) {
    /* Usage */
    if (argc != 3) usage(argv[0], 1);
    if (same_str(argv[1], "--help")) usage(argv[0], 0);
    else if (same_str(argv[1], "--encode")) {
        /* Read in encoded line */
        char encoded_line[BUFSIZ] = {0};
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
    } else if (same_str(argv[1], "--scan")) {
        DEBUG = 1;
        scan(argv[2]);
    } else if (same_str(argv[1], "--parse")) {
        scan(argv[2]);
        parse(argv[2]);
    } else if (same_str(argv[1], "--print")) {
        scan(argv[2]);
        parse(argv[2]);
        struct decl* parser_result = 0;
        pprint(argv[2], parser_result);
    }
    else {
        usage(argv[0], 1);
    }

    return 0;
}


