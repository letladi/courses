#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

struct node {
   void* data;
   struct node *next;
};

struct stack_type {
   struct node *top;
   size_t len;
};

static void terminate(const char* message)
{
   printf("%s\n", message);
   exit(EXIT_FAILURE);
}

Stack create(void)
{
   Stack s = malloc(sizeof(struct stack_type));
   if (s == NULL)
      terminate("Error in create: stack could not be created.");
   s->top = NULL;
   s->len = 0;
   return s;
}

void destroy(Stack s)
{
   make_empty(s);
   free(s);
}

void make_empty(Stack s)
{
   while (!is_empty(s))
      pop(s);
}

bool is_empty(Stack s)
{
   return length(s) == 0;
}

bool is_full(Stack s)
{
   return false;
}

void push(Stack s, void* i)
{
   struct node *new_node = malloc(sizeof(struct node));
   if (new_node == NULL)
      terminate("Error in push: stack is full.");

   new_node->data = i;
   new_node->next = s->top;
   s->top = new_node;
   s->len++;
}

void* pop(Stack s)
{
   struct node *old_top;
   void* i;

   if (is_empty(s))
      terminate("Error in pop: stack is empty.");

   old_top = s->top;
   i = old_top->data;
   s->top = old_top->next;
   s->len--;
   free(old_top);
   return i;
}

void* peek(Stack s)
{
   return s->top->data;
}

size_t length(Stack s)
{
   return s->len;
}