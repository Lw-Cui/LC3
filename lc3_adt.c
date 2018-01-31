#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
#include <string.h>
#include <zconf.h>
#include "lc3_adt.h"

static const int MIN_SIZE = 5;

static char *c_str(String *vec) {
    char *str = malloc(sizeof(char) * vec->len + 1);
    for (int i = 0; i < vec->len; i++) {
        str[i] = *(char *) vec->body[i];
    }
    str[vec->len] = 0;
    return str;
}

static int roundup(int n) {
    int r = 1;
    while (n > r) r <<= 2;
    return r;
}

static void resize(Vector *vec, int n) {
    vec->capacity = roundup(n);
    void **p = malloc(sizeof(void *) * vec->capacity);
    memcpy(p, vec->body, sizeof(void *) * vec->len);
    free(vec->body);
    vec->body = p;
}

Vector *make_vector() {
    Vector *p = malloc(sizeof(Vector));
    p->len = 0;
    p->capacity = roundup(MIN_SIZE);
    p->body = malloc(sizeof(void *) * p->capacity);
    return p;
}

void vec_push_back(Vector *vec, void *ptr) {
    if (vec->len == vec->capacity - 1) {
        resize(vec, vec->capacity * 2);
    }
    vec->body[vec->len++] = ptr;
}


void **get_array(Vector *vec) {
    return vec->body;
}

void *at(Vector *vec, int i) {
    return vec->body[i];
}

String *make_string(char *buf) {
    String *str = malloc(sizeof(String));
    str = make_vector();
    int len = (int) strlen(buf);
    for (int i = 0; i < len; i++) {
        char *p = malloc(sizeof(char));
        *p = buf[i];
        vec_push_back(str, p);
    }
    return str;
}

char *str(String *str) {
    if (str == NULL) return "";
    else return c_str(str);
}

void *back(Vector *vec) {
    return vec->body[size(vec) - 1];
}

int size(Vector *vec) {
    return vec->len;
}


String *sprint(char *fmt, ...) {
#define MAXLINE 500
    char buf[MAXLINE];
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(buf, MAXLINE, fmt, ap);
    va_end(ap);
    return make_string(buf);
}

void vec_pop_back(Vector *vec) {
    vec->len--;
}