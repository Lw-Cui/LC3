#include "lc3_func.h"
#include "lc3_state.h"
#include "lc3_var.h"

Entity *function_definition(Entity *function_declaration, Entity *compound_statement) {
    return compound_statement;
}

Entity *function_declaration(Entity *declaration_specifiers, Entity *declarator) {
    Symbol *symbol = make_symbol(FUNCTION_DECLARATION, declaration_specifiers, declarator);
    add_symbol((Entity *) symbol);
    return (Entity *) symbol;
}

