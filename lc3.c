#include "lc3.h"
#include <stdio.h>
#include <zconf.h>

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
