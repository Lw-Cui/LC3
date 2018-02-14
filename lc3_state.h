#ifndef LC3_ASSEMBLY_H
#define LC3_ASSEMBLY_H

#include "lc3.h"

void set_output_file(FILE *file);

FILE *get_output_file();

void init_symbol_table();

void add_to_symbol_table(Entity *);

#endif
