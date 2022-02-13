#ifndef __LIST_H__
#define __LIST_H__

struct list;

struct list *list_init();

void list_free(struct list *list);

void list_clear(struct list *list);

int list_count(struct list *list);

int list_isempty(struct list *list);

int list_lookup(struct list *list, int e);

int list_get(struct list *list, int index);

void list_set(struct list *list, int index, int e);

void list_add(struct list *list, int index, int e);

int list_remove(struct list *list, int index);

#endif
