#ifndef LC3_TYPE_H
#define LC3_TYPE_H

#include "lc3_adt.h"
#include "lc3.h"

typedef enum {
    INT_TYPE,
} Data_Type;

typedef struct {
    Entity *base;
    Data_Type rel_type;
} Type;

Type *new_type(Data_Type);

typedef struct {
    Entity *base;
    Type basic_type;
    String *name;
} Id;

Id *new_id(char *);

#endif //LC3_TYPE_H