#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

void make_empty(void);
void stack_overflow(void);
void stack_underflow(void);
bool is_empty(void);
bool is_full(void);
void push(int);
int pop(void);

#endif
