#include "lc3_func.h"
#include "lc3_state.h"
#include "lc3_var.h"
#include "lc3.h"

Entity *function_definition(Entity *function_declaration, Entity *compound_statement) {
    Entity *func = new_entity(FUNCTION_DEFINITION);
    func->assembly = merge_assembly(function_declaration->assembly, compound_statement->assembly);
    // TODO: allocate space for function var
    assembly_push_back(func->assembly, make_string("\tpopq   %rbp"));
    assembly_push_back(func->assembly, make_string("\tret\n"));
    return func;
}

void get_func_arguments(Entity *decl) {
    // TODO: allocate space for function argument
}

Entity *function_decl_with_def(Entity *declaration_specifiers, Entity *declarator) {
    Symbol *symbol = add_symbol_table_node(FUNCTION_DECL_WITH_DEF, declaration_specifiers, declarator);
    add_to_symbol_table((Entity *) symbol);
    Assembly *as = symbol->base.assembly;
    char *name = str(symbol->id->name);
    assembly_push_back(
        as,
        sprint("\t.globl %s\n\t.type  %s, @function", name, name));
    assembly_push_back(as, sprint("%s:", name));
    assembly_push_back(as, make_string("\tpushq  %rbp"));
    assembly_push_back(as, make_string("\tmovq   %rsp, %rbp"));

    get_func_arguments(declarator);
    return (Entity *) symbol;
}

