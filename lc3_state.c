#include "lc3_state.h"

static FILE *output = NULL;

void set_output_file(FILE *file) {
    output = file;
}

FILE *get_output_file() {
    return output;
}
