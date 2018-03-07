/*
 * This file is for global interface for all lc3.
 */

#ifndef LC3_H
#define LC3_H

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <zconf.h>
#include "lc3_adt.h"

#define YYSTYPE Entity *

#define MALLOC(type) ((type*) calloc(1, sizeof(type)))

typedef enum {
    TYPE_SPECIFIER,             // basic type: int
    DIRECT_DECLARATOR,          // variable name: tmp
    INT_CONSTANT,               // const int: 0
    JUMP_STATEMENT,             // return a;
    FUNCTION_DECL_WITH_DEF,     // part of function decl: int main()
    SYMBOL,                     // general symbol
    FUNCTION_DEFINITION,        // real function body
} Attribute;

typedef struct {
    Attribute attr;
    Assembly *assembly;
} Entity;

Entity *new_entity(Attribute);

void fill_entity(Entity *, Attribute);

void info(const char *fmt, ...);

Entity *type_specifier_int_type();

Entity *direct_declarator_ref_var(char *);

Entity *constant_int(char *);

Entity *jump_statement_return_expr(Entity *);

Entity *translation_unit_output(Entity *);

Entity *block_item_list_merge(Entity *, Entity *);

Entity *function_definition(Entity *, Entity *);

Entity *function_decl_with_def(Entity *, Entity *);

void enter_new_scope();

void exit_cur_scope();

#endif //LC3_H
