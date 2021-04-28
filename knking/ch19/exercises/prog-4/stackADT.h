#ifndef STACKADT_H
#define STACKADT_H

#include <stdbool.h>
#include <stddef.h>

typedef struct stack_type *Stack;

Stack create(void);
void destroy(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
bool is_full(Stack s);
void push(Stack s, void *);
void* pop(Stack s);
void* peek(Stack s);
size_t length(Stack s);

#endif