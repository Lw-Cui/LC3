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

typedef struct String_Node {
    struct String_Node *prev, *next;
    String *body;
} String_Node;

String_Node *make_str_list(String_Node *prev, String *body, String_Node *next);

typedef struct {
    String_Node *beg, *end;
} Assembly;

Assembly *make_assembly();

void assembly_push_back(Assembly *, String *);

typedef struct Symbol_table {
    Vector *siblings;
    struct Symbol_table *parent;
} Symbol_table;

Symbol_table *make_symbol_table(Symbol_table *);

#endif //LC3_ADT_H
