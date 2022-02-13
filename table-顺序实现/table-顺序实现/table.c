#include "table.h"

#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define TABLE_INIT_SIZE 10
#define TABLE_INCR_SIZE 10

struct table {
   struct element *elements;
   int count;
   int size;      
};

struct table *table_init()
{
    struct table *t = NULL;
    
    t = (struct table *)malloc(sizeof(struct table));
    if (t == NULL) return NULL;
    
    assert(t != NULL);
    t->elements = NULL;
    t->size = 0;
    t->count = 0;
    
    t->elements = (struct element *)malloc(sizeof(struct element) * TABLE_INIT_SIZE);
    if (t->elements == NULL) {
       free(t);
       return NULL;                
    }
    
    assert(t->elements != NULL);
    memset(t->elements, 0, sizeof(struct element) * TABLE_INIT_SIZE);
    t->size = TABLE_INIT_SIZE;
    
    return t;
}

void table_free(struct table *t)
{
    assert(t != NULL);
    assert(t->elements != NULL);
    
    free(t->elements);
    free(t);
    
    return;     
}

int table_isempty(struct table *t)
{
    assert(t != NULL);
    assert(t->elements != NULL);
    
    return t->count == 0;
}

int table_count(struct table *t)
{
    assert(t != NULL);
    assert(t->elements != NULL);
    
    return t->count;    
}

void table_clear(struct table *t)
{
    assert(t != NULL);
    assert(t->elements != NULL);
    
    t->count = 0;
    
    return;     
}

void table_put(struct table *t, int key, int value)
{
    struct element e;
    int i;
    
    e.key = key;
    e.value = value;
    
    for (i = 0; i < t->count; i++) {
        if (t->elements[i].key == e.key) {
           t->elements[i].value = e.value;
           return;                       
        }
    }
    
    t->elements[t->count] = e;//t->elements[i]
    t->count++;
    
    return;
}

struct element table_remove(struct table *t, int key)
{
    int i;
    int flag = -1;
    struct element e = {-1, -1};
    
    for (i = 0; i < t->count; i++) {
        if (t->elements[i].key == key) {
            e = t->elements[i];
            flag = i;
            break;                       
        }
    }
    
    for (i = flag; i < t->count-1; i++) {
        t->elements[i] = t->elements[i+1];    
    }
    
    if (flag >= 0) t->count--;
    
    return e;
}

/*
   {-1, -1} ц╩спур╣╫ 
*/
struct element table_get(struct table *t, int key)
{
    int i;
    struct element err = {-1, -1};    

    
    for (i = 0; i < t->count; i++) {
        if (t->elements[i].key == key) 
           return t->elements[i];
    }
    
    return err;
}
