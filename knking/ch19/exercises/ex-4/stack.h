#ifndef STACKADT_H
#define STACKADT_H

#include <stdbool.h>

typedef struct stack_type *Stack;
typedef void *Item;

Stack create(size_t);
void destroy(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
bool is_full(Stack s);
bool push(Stack s, Item i);
Item pop(Stack s);
Item top(Stack s);

#endif