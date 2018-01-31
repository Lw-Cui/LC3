#include "lc3_var.h"
#include "lc3.h"

Type *new_type(Data_Type data_type) {
    Type *type = MALLOC(Type);
    type->base = new_entity(TYPE_SPECIFIER);
    type->rel_type = data_type;
    return type;
}

Id *new_id(char *name) {
    Id *id = MALLOC(Id);
    id->base = new_entity(DIRECT_DECLARATOR);
    id->name = make_string(name);
    return id;
}
