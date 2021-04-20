#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define STACK_SIZE 100
#define PUBLIC
#define PRIVATE static

PRIVATE int contents[STACK_SIZE];
PRIVATE int top = 0;

PRIVATE void terminate(const char* message)
{
   printf("%s\n", message);
   exit(EXIT_FAILURE);
}

PUBLIC void make_empty(void)
{
   top = 0;
}

PUBLIC bool is_empty(void)
{
   return top == 0;
}

PUBLIC bool is_full(void)
{
   return top == STACK_SIZE;
}

PUBLIC void push(int i)
{
   if (is_full())
      terminate("Error in push: stack is full.");

   contents[top++] = i;
}

PUBLIC int pop(void)
{
   if (is_empty())
      terminate("Error in pop: stack is empty.");
   return contents[--top];
}