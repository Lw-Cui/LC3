#include <stdio.h>
#include "lc3_state.h"

extern FILE *yyin;

extern int yyparse();

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 0;
    }
    yyin = fopen(argv[1], "r");

    char output[50];
    sprintf(output, "%s.asm", argv[1]);
    set_output_file(fopen(output, "w"));

    init_symbol_table();

    yyparse();

    fclose(yyin);
    return 0;
}

