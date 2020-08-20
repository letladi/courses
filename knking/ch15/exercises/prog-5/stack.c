#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"

#define STACK_SIZE 100
/* external variables */
int contents[STACK_SIZE];
int top = 0;

void make_empty(void)
{
   top = 0;
}

void stack_underflow()
{
   printf("cannot read empty stack. Exiting...\n");
   exit(EXIT_FAILURE);
}

void stack_overflow()
{
   printf("cannot add to full stack. Exiting...\n");
   exit(EXIT_FAILURE);
}

bool is_empty(void)
{
   return top == 0;
}

bool is_full(void)
{
   return top == STACK_SIZE;
}

void push(int i)
{
   if (is_full()) stack_overflow();
   else contents[top++] = i;
}

int pop(void)
{
   if (is_empty()) stack_underflow();
   else return contents[--top];
}
