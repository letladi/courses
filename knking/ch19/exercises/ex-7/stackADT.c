#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

#define STACK_SIZE 100

struct stack_type {
   Item *contents;
   int top;
   int size;
};

static void terminate(const char* message)
{
   printf("%s\n", message);
   exit(EXIT_FAILURE);
}

Stack create(int size)
{
   Stack s = malloc(sizeof(struct stack_type));
   if (s == NULL)
      terminate("Error in create: stack could not be created.");
   s->contents = malloc(size * sizeof(Item));
   if (s->contents == NULL) {
      free(s);
      terminate("Error in create: stack could not be created.");
   }
   s->top = 0;
   s->size = size;
   return s;
}

void destroy(Stack s)
{
   free(s->contents);
   free(s);
}

void make_empty(Stack s)
{
   s->top = 0;
}

bool is_empty(Stack s)
{
   return s->top == 0;
}

bool is_full(Stack s)
{
   return s->top == s->size;
}

void push(Stack s, int i)
{
   if (is_full(s)) {
      int new_size = s->size * 2;
      Item *new_contents = malloc(new_size * sizeof(Item));
      if (new_contents) {
         int i = 0;
         while (i < s->size) {
            new_contents[i] = s->contents[i];
            i++;
         }
         free(s->contents);
         s->contents = new_contents;
         s->size = new_size;
      } else {
         terminate("Error in push: stack is full.");
      }
   }
      
   s->contents[s->top++] = i;
}

int pop(Stack s)
{
   if (is_empty(s))
      terminate("Error in pop: stack is empty.");
   return s->contents[--s->top];
}

Item peek(Stack s)
{
   return s->contents[s->top - 1];
}

