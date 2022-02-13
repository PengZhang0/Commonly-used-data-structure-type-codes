#ifndef __TABLE_H__
#define __TABLE_H__

struct table;

struct element {
   int key;
   int value;       
};

struct table *table_init();
void table_free(struct table *t);

int table_isempty(struct table *t);
int table_count(struct table *t);
void table_clear(struct table *t);

void table_put(struct table *t, int key, int value);
struct element table_remove(struct table *t, int key);

/* {-1, -1} ц╩спур╣╫ */ 
struct element table_get(struct table *t, int key);

#endif  /* __TABLE_H__ */
