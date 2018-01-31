#include "lc3.h"
#include "lc3_var.h"

void info(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    fprintf(stderr, "========INFO========\n");
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, "\n========INFO========");
    fprintf(stderr, "\n");
    va_end(ap);
}

Entity *new_entity(Attribute attribute) {
    Entity *entity = MALLOC(Entity);
    entity->attr = attribute;
    return entity;
}

Entity *type_specifier_int_type() {
    Type *type = new_type(INT_TYPE);
    return (Entity *) type;
}

Entity *direct_declarator_ref_var(char *name) {
    Id *id = new_id(name);
    return (Entity*)id;
}

