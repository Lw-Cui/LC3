#include "lc3_var.h"
#include "lc3.h"

Type *new_type(Data_Type data_type) {
    Type *type = MALLOC(Type);
    fill_entity(&type->base, TYPE_SPECIFIER);
    type->rel_type = data_type;
    return type;
}

Id *new_id(char *name) {
    Id *id = MALLOC(Id);
    fill_entity(&id->base, DIRECT_DECLARATOR);
    id->name = make_string(name);
    return id;
}

Const_int *new_const_int(char *str) {
    Const_int *const_int = MALLOC(Const_int);
    fill_entity(&const_int->base, INT_CONSTANT);
    // TODO: Assume that str is interpreted as 10-based integer
    const_int->val = strtol(str, NULL, 10);
    return const_int;
}
