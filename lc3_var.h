#ifndef LC3_TYPE_H
#define LC3_TYPE_H

#include "lc3.h"

typedef enum {
    INT_TYPE,
} Data_Type;

typedef struct {
    Entity base;
    Data_Type rel_type;
} Type;

Type *new_type(Data_Type);

typedef struct {
    Entity base;
    Type basic_type;
    String *name;
} Id;

Id *new_id(char *);

typedef struct {
    Entity base;
    Attribute symbol_attr;
    Type *type;
    Id *id;
} Symbol;

Symbol *make_symbol(Attribute attr, Entity *type, Entity *id);

typedef struct {
    Entity base;
    long long int val;
} Const_int;

Const_int *new_const_int(char *);

#endif //LC3_TYPE_H
