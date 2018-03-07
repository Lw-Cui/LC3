#include "lc3_var.h"

/*
 * Return new specifier(int) type
 */
Entity *type_specifier_int_type() {
    Type *type = new_type(INT_TYPE);
    return (Entity *) type;
}

Type *new_type(Data_Type data_type) {
    Type *type = MALLOC(Type);
    fill_entity(&type->base, TYPE_SPECIFIER);
    type->rel_type = data_type;
    return type;
}

/*
 * Normal variable definition
 */
Entity *direct_declarator_ref_var(char *name) {
    Id *id = new_id(name);
    return (Entity *) id;
}

/*
 * New a id struct
 */
Id *new_id(char *name) {
    Id *id = MALLOC(Id);
    fill_entity(&id->base, DIRECT_DECLARATOR);
    id->name = make_string(name);
    return id;
}

/*
 * return a constant_int
 */
Entity *constant_int(char *str) {
    return (Entity *) new_const_int(str);
}

/*
 * New a const_int struct
 */
Const_int *new_const_int(char *str) {
    Const_int *const_int = MALLOC(Const_int);
    fill_entity(&const_int->base, INT_CONSTANT);
    // TODO: Assume that str is interpreted as 10-based integer
    const_int->val = strtol(str, NULL, 10);
    return const_int;
}

/*
 * Return a new symbol table node: <type, id> with attr.
 * Take `int main(int b) { return 0; }` as an example:
 *      int                     -> type
 *      main(int b)             -> id
 *      FUNCTION_DECL_WITH_DEF  -> attr
 */
Symbol *new_symbol_table_node(Attribute attr, Entity *type, Entity *id) {
    Symbol *ptr = MALLOC(Symbol);
    fill_entity(&ptr->base, SYMBOL);
    ptr->symbol_attr = attr;
    // TODO: more type
    if (type->attr == TYPE_SPECIFIER) ptr->type = (Type *) type;
    if (id->attr == DIRECT_DECLARATOR) ptr->id = (Id *) id;
    return ptr;
}


