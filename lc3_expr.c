#include "lc3_var.h"

String *assembly_gen(char *fmt, ...) {
#define MAXLINE 500
    char buf[MAXLINE];
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(buf, MAXLINE, fmt, ap);
    va_end(ap);
    return make_string(buf);
}

Entity *jump_statement_return_expr(Entity *expr) {
    Entity *entity = new_entity(JUMP_STATEMENT);
    // TODO: what if other expr is returned?
    if (expr->attr == INT_CONSTANT) {
        Const_int *const_int = (Const_int *) expr;
        assembly_push_back(
            entity->assembly,
            assembly_gen("\tmovq   $%d, %%rax", const_int->val));
    }
    return entity;
}

Entity *block_item_list_merge(Entity *dest, Entity *src) {
    dest->assembly = merge_assembly(dest->assembly, src->assembly);
    return dest;
}

