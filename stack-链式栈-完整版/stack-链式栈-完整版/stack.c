#include "stack.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

struct stack_node {
   int value;
   struct stack_node *next;
};

struct stack {
   struct stack_node *top;  /* stack top */
   int count;
};

struct stack *stack_init()
{
   struct stack *s = NULL;
   
   s = (struct stack *)malloc(sizeof(struct stack));
   if (s == NULL) return NULL;

   s->top = NULL;
   s->count = 0;
   
   return s;
}

void stack_free(struct stack *s)
{
   struct stack_node *node = NULL;
   
   while (s->top) {
       node = s->top;
       s->top = node->next;
       free(node);
   }
   
   assert(s->top == NULL);
   free(s);
   
   return;
}

int stack_isempty(const struct stack *s)
{
   return s->count == 0;
}

int stack_count(const struct stack *s)
{  
   return s->count;    
}

void stack_clear(struct stack *s)
{
   struct stack_node *node = NULL;
   
   while (s->top) {
       node = s->top;
       s->top = node->next;
       
       free(node);
       s->count--;
   }

   return;
}

void stack_push(struct stack *s, int value)
{
   struct stack_node *node = NULL;
   
   node = (struct stack_node *)malloc(sizeof(struct stack_node));
   if (node == NULL) {
       perror("stack_push() malloc failed in stack.c");
       exit(0);
   }
   
   node->next = NULL;
   node->value = value;
   
   node->next = s->top;
   s->top = node;
   
   s->count++;
   
   return;    
}

int stack_pop(struct stack *s)
{
    struct stack_node *node = NULL;
    int ret;
    
    node = s->top;
    s->top = node->next;
    ret = node->value;
    free(node);
    s->count--;
    return ret;
}

int stack_top(const struct stack *s)
{
    return s->top->value;
}
