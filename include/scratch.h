#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define SCRATCH_SIZE 7

typedef struct {
    bool inuse;    
    const char* name;
} scratch_entry;


int         scratch_alloc();
void        scratch_free(int r);
const char* scratch_name(int r);
