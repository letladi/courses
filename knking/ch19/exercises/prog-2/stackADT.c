#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

struct node {
   Item data;
   struct node *next;
};

struct stack_type {
   struct node *top;
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
      return NULL;
   s->top = NULL;
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
   return s->top == NULL;
}

bool is_full(Stack s)
{
   return false;
}

bool push(Stack s, Item i)
{
   struct node *new_node = malloc(sizeof(struct node));
   if (new_node == NULL)
     return false;

   new_node->data = i;
   new_node->next = s->top;
   s->top = new_node;
}

Item pop(Stack s)
{
   struct node *old_top;
   Item i;

   if (is_empty(s))
      return NULL;

   old_top = s->top;
   i = old_top->data;
   s->top = old_top->next;
   free(old_top);
   return i;
}

Item peek(Stack s)
{
   if (is_empty(s))
      return NULL;

   return s->top->data;
}