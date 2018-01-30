#ifndef LC3_TYPE_H
#define LC3_TYPE_H

#include "lc3.h"

typedef enum {
    INT_TYPE,
} Data_Type;

typedef struct {
    Entity *base;
    Data_Type type;
} Type;

Type *new_type(Data_Type);

#endif //LC3_TYPE_H
