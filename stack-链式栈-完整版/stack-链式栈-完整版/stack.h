#ifndef __STACK_H__
#define __STACK_H__

struct stack;

struct stack *stack_init();
void stack_free(struct stack *s);

int stack_isempty(const struct stack *s);
int stack_count(const struct stack *s);
void stack_clear(struct stack *s);

void stack_push(struct stack *s, int value);
int stack_pop(struct stack *s);
int stack_top(const struct stack *s);

#endif /* __STACK_H__ */
