#include "../include/scratch.h"
#include <stdint.h>

scratch_entry scratch_table[SCRATCH_SIZE] = {{false, "%rbx"}, {false, "%r10"}, {false, "%r11"}, {false, "%r12"}, {false, "%r13"}, {false, "%r14"}, {false, "%r15"}};

/* Function to find a free scratch register */
int scratch_alloc() {
	for (int i = 0; i < SCRATCH_SIZE; i++) {
		if (!scratch_table[i].inuse) {
			scratch_table[i].inuse = true;
			return i;
		}
	}
	fprintf(stdout, "ERROR: No free scratch registers.\n");
	exit(1);
}

/* Function to return a registers name given its name */
const char* scratch_name(int r) {
	return scratch_table[r].name;
}

/* Function to mark a register as unused */
void scratch_free(int r) {
	scratch_table[r].inuse = false;
}
