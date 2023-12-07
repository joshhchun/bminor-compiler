#include "../include/label.h"

int NUM_LABELS = 0;

/* Function to increment the global label counter and return the val */
int label_create() {
    return ++NUM_LABELS;
}

/* Returns a label in string form */
const char* label_name(int label) {
    char temp[BUFSIZ] = {0}, *label_n = 0;
    sprintf(temp, ".L%d", label);
    if (!(label_n = strdup(temp))) {
        fprintf(stdout, "ERROR: Not enough memory to allocate label name.\n");
        exit(1);
    };
    return label_n;
}
