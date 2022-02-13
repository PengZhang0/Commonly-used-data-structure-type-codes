#include "list.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LIST_INIT_SIZE 10
#define LIST_INCR_SIZE 10

struct list{
	int *elements;
	int size;
	int count;
};

struct list *list_init()
{
	struct list *list = NULL;
	list = (struct list *)malloc(sizeof(struct list));
	if(list == NULL) return NULL;
	
	list->count = 0;
	list->elements = NULL;
	list->size = 0;
	
	list->elements = (int *)malloc(sizeof(int) * LIST_INIT_SIZE);
	if(list->elements == NULL){
		free(list->elements);
		free(list);
		return NULL;
	}
	
	list->size = LIST_INIT_SIZE;
	memset(list->elements, 0, sizeof(int) * LIST_INIT_SIZE);
	return list;
}

void list_free(struct list *list)
{
	free(list->elements);
	free(list);
}

void list_clear(struct list *list)
{
	list->count = 0;
	return;
}

int list_count(struct list *list)
{
	return list->count;
}

int list_isempty(struct list *list)
{
	return list->count == 0;
}

int list_lookup(struct list *list, int value)
{
	int i;
	for(i = 0; i < list->count; i++){
		if(list->elements[i] == value) return 1;
	}
	
	return 0;
}

int list_get(struct list *list, int index)
{
	return list->elements[index];
}

void list_add(struct list *list, int index, int value)
{
	int i;
	if(list->count == list->size){
		int *p = NULL;
		p = (int *)malloc(sizeof(int) * (list->size + LIST_INCR_SIZE));
		if(p == NULL){
			perror("1");
			exit(1);
		}
		
		list->size += LIST_INCR_SIZE;
		list->elements = p;
	}
	
	for(i = list->count-1; i >= index; i--){
		list->elements[i+1] = list->elements[i];
	}
	
	list->elements[index] = value;
		
	list->count++;
	return;
}

void list_set(struct list *list, int index, int value)
{
	list->elements[index] == value;
}

int list_remove(struct list *list, int index)
{
	int i;
	int ret;
	ret = list->elements[index];
	
	for(i = index-1; i < list->count; i++){
		list->elements[i-1] = list->elements[i];
	}
	
	return ret;
}
