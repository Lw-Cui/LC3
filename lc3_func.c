#include "lc3_func.h"
#include "lc3_symtab.h"
#include "lc3_var.h"
#include "lc3.h"

/*
 * Real function definition, which include the compound_statement
 */
Entity *function_definition(Entity *func_decl, Entity *stats) {
    Entity *func = new_entity(FUNCTION_DEFINITION);
    func->assembly = merge_assembly(func_decl->assembly, stats->assembly);
    // TODO: allocate space for function var
    assembly_push_back(func->assembly, make_string("\tpopq   %rbp"));
    assembly_push_back(func->assembly, make_string("\tret\n"));
    return func;
}

/*
 * For function arguments
 */
void get_func_arguments(Entity *decl) {
    // TODO: allocate space for function argument
}

/*
 * Here we have to separate function declaration with its definition:
 *      since recursion may occur in its body, its signature must be added into symbol table
 */
Entity *function_decl_with_def(Entity *decl_spec, Entity *declarator) {
    // Take `int main(int b)` as an example:
    //      int         -> decl_spec
    //      main(int b) -> declarator
    Symbol *symbol = new_symbol_table_node(FUNCTION_DECL_WITH_DEF, decl_spec, declarator);
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

