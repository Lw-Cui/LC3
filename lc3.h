#ifndef LC3_H
#define LC3_H

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <zconf.h>

#define YYSTYPE Entity *

#define MALLOC(type) ((type*) calloc(1, sizeof(type)))

typedef enum {
    TYPE_SPECIFIER,             // basic type: int
    DIRECT_DECLARATOR,          // variable name: tmp
} Attribute;

typedef struct {
    Attribute attr;
} Entity;

Entity *new_entity(Attribute);

void info(const char *fmt, ...);

Entity *type_specifier_int_type();

Entity *direct_declarator_ref_var(char *);

#endif //LC3_H
