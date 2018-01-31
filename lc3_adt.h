#ifndef LC3_ADT_H
#define LC3_ADT_H

typedef struct {
    void **body;
    int len;
    int capacity;
} Vector;

Vector *make_vector();

void **get_array(Vector *vec);

int size(Vector *vec);

void *back(Vector *vec);

void vec_pop_back(Vector *vec);

void vec_push_back(Vector *vec, void *ptr);

void *at(Vector *vec, int i);

typedef Vector String;

String *make_string(char *);

char *str(String *);

String *sprint(char *fmt, ...);


#endif //LC3_ADT_H
