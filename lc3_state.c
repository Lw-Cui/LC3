#include "lc3.h"
#include "lc3_state.h"
#include "lc3_var.h"

static FILE *output = NULL;

void set_output_file(FILE *file) {
    output = file;
}

FILE *get_output_file() {
    return output;
}

static Symbol_table *cur_symbol = NULL;

void init_symbol_table() {
    cur_symbol = make_symbol_table(NULL);
}

void enter_new_scope() {
    cur_symbol = make_symbol_table(cur_symbol);
}

void exit_cur_scope() {
    cur_symbol = cur_symbol->parent;
}

void add_symbol(Entity *symbol) {
    // TODO: throw error
    //info("add symbol %s", str(((Symbol *)symbol)->id->name));
    if (symbol->attr == SYMBOL)
        vec_push_back(cur_symbol->siblings, (Symbol *) symbol);
}

