#include "table.h"

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

#define TABLE_INIT_SIZE 10 

struct table_node {
    struct element e;
    struct table_node *next;       
};

struct table {
    struct table_node **slots;
    int size;
    int count;       
};

struct table *table_init()
{
    struct table *t = NULL;
    
    t = (struct table *)malloc(sizeof(struct table)); 
    if (t == NULL) return NULL;
    
    assert(t != NULL);
    t->slots = NULL;
    t->size = 0;
    t->count = 0;
    
    t->slots = (struct table_node **)malloc(sizeof(struct table_node *) * TABLE_INIT_SIZE);
    if (t->slots == NULL) {
       free(t);
       return NULL;            
    }
    
    assert(t->slots != NULL);
    memset(t->slots, 0, sizeof(struct table_node *) * TABLE_INIT_SIZE);
    t->size = TABLE_INIT_SIZE;
    
    return t;
}

void table_free(struct table *t)
{
    struct table_node *node = NULL;
    int i;
    
    assert(t != NULL);
    assert(t->slots != NULL);
    
    for (i = 0; i < t->size; i++) {
        while (t->slots[i] != NULL) {
            node = t->slots[i];
            t->slots[i] = node->next;
            free(node);
        }
    }
    
    free(t->slots);
    free(t);
    
    return;   
}

int table_isempty(struct table *t)
{
    assert(t != NULL);
    assert(t->slots != NULL);
    
    return t->count == 0;       
}

int table_count(struct table *t)
{
    assert(t != NULL);
    assert(t->slots != NULL);
    
    return t->count;    
}
void table_clear(struct table *t)
{
    struct table_node *node = NULL;
    int i;
    
    assert(t != NULL);
    assert(t->slots != NULL);
    
    for (i = 0; i < t->size; i++) {
        while (t->slots[i] != NULL) {
            node = t->slots[i];
            t->slots[i] = node->next;
            free(node);
            t->count --;
        }
    }
    
    assert(t->count == 0);
    
    return;
}

void table_put(struct table *t, int key, int value)
{
    struct element e = {key, value};
    struct table_node *node = NULL;
    struct table_node *p = NULL;
    
    p = t->slots[key % t->size];
    while (p != NULL) {
        if (p->e.key == key) {
            p->e.value = value;
            return;             
        }
        p = p->next;
    } 
    
    node = (struct table_node *)malloc(sizeof(struct table_node));
    if (node == NULL) {
         perror("malloc error int table_put()");
         exit(0);          
    }
    
    assert(node != NULL);
    node->e = e;
    
    node->next = t->slots[key % t->size];
    t->slots[key % t->size] = node;
    
    t->count++;
    
    return;
}

struct element table_remove(struct table *t, int key)
{
    struct table_node *node = NULL;
    struct table_node *p = NULL;
    struct element e = {-1, -1};
    
    p = t->slots[key % t->size];
    
    if (p->e.key == key) {
        node = p;
        t->slots[key % t->size] = node->next;
        e = node->e;
        free(node);
        t->count--;
        return e;             
    }
    
    while (p != NULL && p->next != NULL) {
        if (p->next->e.key == key) {
             node = p->next;
             p->next = node->next;
             e = node->e;
             free(node);
             t->count--;
             return e;
        }
        p = p->next;
    }
    
    return e;    
}

/* {-1, -1} ц╩спур╣╫ */ 
struct element table_get(struct table *t, int key)
{
    struct element e = {-1, -1};
    struct table_node *p = NULL;
    
    p = t->slots[key % t->size];
    while (p != NULL) {
        if (p->e.key == key) {
            return p->e;             
        }
        p = p->next;
    }
    
    return e;
}
