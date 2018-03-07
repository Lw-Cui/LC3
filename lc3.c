/*
 * This file is for global definition which cannot be classified in others.
 */
#include "lc3.h"
#include "lc3_symtab.h"

/*
 * for debug usage.
 */
void info(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    fprintf(stderr, "========INFO========\n");
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, "\n========INFO========");
    fprintf(stderr, "\n");
    va_end(ap);
}

/*
 * manipulate the attr of entity
 */
void fill_entity(Entity *entity, Attribute attribute) {
    entity->attr = attribute;
    entity->assembly = make_assembly();
}

/*
 * new a entity, which is the basic class for all others
 */
Entity *new_entity(Attribute attr) {
    Entity *entity = MALLOC(Entity);
    fill_entity(entity, attr);
    return entity;
}

/*
 * Output the final assembly code.
 */
Entity *translation_unit_output(Entity *entity) {
    Assembly *assembly = entity->assembly;
    for (String_Node *cur = assembly->beg->next; cur != assembly->end; cur = cur->next) {
        fprintf(get_output_file(), "%s\n", str(cur->body));
    }
    return entity;
}

