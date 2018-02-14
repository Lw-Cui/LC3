#include "lc3.h"
#include "lc3_var.h"
#include "lc3_state.h"

void info(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    fprintf(stderr, "========INFO========\n");
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, "\n========INFO========");
    fprintf(stderr, "\n");
    va_end(ap);
}

static String *assembly_gen(char *fmt, ...) {
#define MAXLINE 500
    char buf[MAXLINE];
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(buf, MAXLINE, fmt, ap);
    va_end(ap);
    return make_string(buf);
}

void fill_entity(Entity *entity, Attribute attribute) {
    entity->attr = attribute;
    entity->assembly = make_assembly();
}

Entity *type_specifier_int_type() {
    Type *type = new_type(INT_TYPE);
    return (Entity *) type;
}

Entity *direct_declarator_ref_var(char *name) {
    Id *id = new_id(name);
    return (Entity *) id;
}

Entity *constant_int(char *str) {
    return (Entity *) new_const_int(str);
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

Entity *new_entity(Attribute attr) {
    Entity *entity = MALLOC(Entity);
    fill_entity(entity, attr);
    return entity;
}

Entity *translation_unit_output(Entity *entity) {
    Assembly *assembly = entity->assembly;
    for (String_Node *cur = assembly->beg->next; cur != assembly->end; cur = cur->next) {
        fprintf(get_output_file(), "%s\n", str(cur->body));
    }
    return entity;
}

Entity *block_item_list_merge(Entity *dest, Entity *src) {
    dest->assembly = merge_assembly(dest->assembly, src->assembly);
    return dest;
}

