#include "lc3_type.h"
#include "lc3.h"

Entity *type_specifier_int_type() {
    Type *type = new_type(INT_TYPE);
    return (Entity *) type;
}

Type *new_type(Data_Type data_type) {
    Type *type = MALLOC(Type);
    type->base = new_entity(TYPE_SPECIFIER);
    type->type = data_type;
    return type;
}
