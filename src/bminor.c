#include "../include/bminor.h"
#include <stdlib.h>

int ERR_COUNT = 0;
p_type PROGRAM_TYPE;
struct decl* parser_result;

/**
 *
 * Usage helper
 * Input:  exit code status: int
 * Output: void
 *
 */
void usage(int status) {
    fprintf(stderr, "Usage: bminor [options] file_name\n");
    fprintf(stderr, "\t--encode  : Encode string if valid\n");
    fprintf(stderr, "\t--scan    : Scan a file and print out tokens\n");
    fprintf(stderr, "\t--print   : Build the AST and pretty print source code\n");
    fprintf(stderr, "\t--resolve : Build the AST and perform name resolution\n");
    fprintf(stderr, "\t--codegen : Generate the assembly code for the program\n");
    exit(status);
}

/**
 *
 * Function to indent
 * Input:  # of indents: int
 * Output: void
 *
 */
void indent(int indents){
    for(int i = 0; i < indents; i++) fprintf(stdout, "    ");
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

/**
 *
 * Function to decode and encode a line.
 * Input:  file name: const char*
 * Output: void
 *
 */
void encode(const char* file_name) {
    /* Read in encoded line */
    char encoded_line[BUFSIZ] = {0};
    if (read_input(file_name, encoded_line)) exit(EXIT_FAILURE);

    /* Decode line */
    char decoded_line[MAX_CHAR_LENGTH + 1] = {0};
    if (string_decode((const char *)encoded_line, decoded_line)) exit(EXIT_FAILURE);
    
    /* Clear the encoded line */
    char* end_ptr = encoded_line + strlen(encoded_line);
    for (char *p = encoded_line; (*p = 0) || p < end_ptr; ++p);
    
    /* Encode the line */
    if (string_encode((const char*)decoded_line, encoded_line)) exit(EXIT_FAILURE);
    fprintf(stdout, "Decoded line: %s\n", decoded_line);
    fprintf(stdout, "Encoded line: %s\n", encoded_line);
}

/**
 *
 * Function to scan a file for its tokens
 * Input:  file name: const char*
 * Output: void
 *
 */
void scan(const char* file_name) {
    if (!(yyin = fopen(file_name, "r"))) {
        fprintf(stderr, "Could not open %s\n", file_name);
        exit(EXIT_FAILURE);
    };
    if (scanner()) { 
        exit(EXIT_FAILURE);
    } else 
        if (PROGRAM_TYPE == T_SCAN || PROGRAM_TYPE == T_PARSE) 
            fprintf(stdout, "Program scanned successfully.\n");
        
    fclose(yyin);
}

/**
 *
 * Function to parse the tokens
 * Input:  file name: const char*
 * Output: void
 *
 */
void parse(const char* file_name) {
    if (!(yyin = fopen(file_name, "r"))) {
        fprintf(stderr, "Could not open %s\n", file_name);
        exit(EXIT_FAILURE);
    };
    if (yyparse()) {
        exit(EXIT_FAILURE);
    } else 
        if (PROGRAM_TYPE == T_PARSE)
            fprintf(stdout, "Program parsed successfully.\n");
    fclose(yyin);
}

/**
 *
 * Function to pretty print the AST
 * Input:  parser result: struct decl*
 * Output: void
 *
 */
void pprint(struct decl* parser_result) {
    decl_print_list(parser_result, 0);
}

/**
 *
 * Function to do name resolution on the AST
 * Input:  parser result: struct decl*
 * Output: void
 *
 */
void resolve(struct decl* parser_result) {
    create_symbol_table();
    scope_enter();
    decl_resolve(parser_result);
    scope_exit();
}

void codegen(struct decl* parser_result, const char* file_name, const char* write_file) {
    FILE* fp = fopen(write_file, "w");
    fprintf(fp, ".file \"%s\"\n", file_name);
    decl_codegen(parser_result, fp);
}

/**
 *
 * Function to do name resolution on the AST
 * Input:  parser result: struct decl*
 * Output: void
 *
 */
void typecheck(struct decl* parser_result) {
    decl_typecheck(parser_result);
}

/**
 *
 * Helper function to set the program type (more for debugging purposes)
 * Input:  flag: const char*
 * Output: void
 *
 */
void set_program_type (const char* flag) {
    if (same_str(flag, "--encode")) {
        PROGRAM_TYPE = T_ENCODE;
    } else if (same_str(flag, "--scan")) {
        PROGRAM_TYPE = T_SCAN;
    } else if (same_str(flag, "--parse")) {
        PROGRAM_TYPE = T_PARSE;
    } else if (same_str(flag, "--print")) {
        PROGRAM_TYPE = T_PRINT;
    } else if (same_str(flag, "--resolve")) {
        PROGRAM_TYPE = T_RESOLVE;
    } else if (same_str(flag, "--typecheck")) {
        PROGRAM_TYPE = T_TYPECHECK;
    } else if (same_str(flag, "--codegen")) {
        PROGRAM_TYPE = T_CODEGEN;
    } else if (same_str(flag, "--help")) {
        usage(0);
    } else {
        usage(1);
    }
}

int main(int argc, char** argv) {
    /* Usage */
    if (argc < 4) usage(1);

    set_program_type(argv[1]);
    switch (PROGRAM_TYPE) {
        case T_ENCODE:
            encode(argv[2]);
            break;
        case T_SCAN:
            scan(argv[2]);
            break;
        case T_PARSE:
            scan(argv[2]);
            parse(argv[2]);
            break;
        case T_PRINT:
            scan(argv[2]);
            parse(argv[2]);
            pprint(parser_result);
            break;
        case T_RESOLVE:
            scan(argv[2]);
            parse(argv[2]);
            resolve(parser_result);
            return (ERR_COUNT) ? 1 : 0;
        case T_TYPECHECK:
            scan(argv[2]);
            parse(argv[2]);
            resolve(parser_result);
            if (ERR_COUNT) return 1;
            typecheck(parser_result);
            return (ERR_COUNT) ? 1 : 0;
            break;
        case T_CODEGEN:
            scan(argv[2]);
            parse(argv[2]);
            resolve(parser_result);
            if (ERR_COUNT) return 1;
            typecheck(parser_result);
            if (ERR_COUNT) return 1;
            codegen(parser_result, argv[2], argv[3]);

    }
    return 0;
}


