#include "list.h"

#include <stdlib.h>
#include <assert.h> 

struct list_node {
	int value;
	struct list_node *next;      
};

struct list {
	int count;
	struct list_node *head;
};

struct list *list_init()
{
   struct list *list = NULL;
   list = (struct list *)malloc(sizeof(struct list));
   if(list == NULL) return NULL;
   
   list->count = 0;
   list->head = NULL;
   return list;
}

void list_free(struct list *list)
{
	struct list_node *node = NULL;
	while(list->head != NULL){
		node = list->head;
		list->head = node->next;
		free(node);
	}
	
	free(list);
}

int list_count(struct list *list)
{

    return list->count;
}

int list_isempty(struct list *list)
{ 
    return list->count == 0;    
}

void list_clear(struct list *list)
{
    struct list_node *node = NULL;
    while(list->head != NULL){
    	node = list->head;
    	list->head = node->next;
    	free(node);
	}
}

// 找到了返回1，否则返回0 
int list_lookup(struct list *list, int e)
{
	struct list_node *p = NULL;
	p = list->head;
	while(p != NULL){
		if(p->value == e) return 1;
		p = p->next;
	}
	
	return 0;
}
// index >= 0 && index < count
int list_get(struct list *list, int index)
{
	struct list_node *p = NULL;
	int i;
	i = 0;
	p = list->head;
	while(p != NULL && i < index){
		p = p->next;
		i++;
	}
	return p->value;
}

void list_set(struct list *list, int index, int e)
{
	struct list_node *p = NULL;
	int i;
	i = 0;
	p = list->head;
	while(p != NULL && i < index){
		p = p->next;
		i++;
	}
	
	p->value = e;
}

int list_remove(struct list *list, int index)
{
    struct list_node *p = NULL;
    struct list_node *node = NULL;
    
    int i, ret;
    
    if(index ==0){
    	node = list->head;
    	list->head = node->next;
    	ret = node->value;
    	list->count--;
    	free(node);
    	return ret;
	}
	
	i = 0;
	p = list->head;
	while(p != NULL & i < index){
		p = p->next;
		i++;
	}
	
	node = p->next;
	p->next = node->next;
	free(node);
	list->count--;
	return ret;
}

// index >= 0 && index <= count
void list_add(struct list *list, int index, int e)
{
   struct list_node *p = NULL;
   struct list_node *node = NULL;
   int i;
   
   node = (struct list_node *)malloc(sizeof(struct list_node));
   if(node == NULL){
   	perror("1");
   	exit(1);
   }
   
   node->next = NULL;
   node->value = e;
   
   if(index == 0){
		node->next = list->head;
		list->head = node;
		list->count++;
		return;
   }
   
   i = 0;
   p = list->head;
   
   while(p != NULL && i < index -1){
   	p = p->next;
   	i++;
   }
   
   node->next = p->next;
   p->next = node;
   list->count++;
   return;
}
