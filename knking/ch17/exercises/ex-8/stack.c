#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

struct node
{
   int value;
   struct node *next;
};

struct node *top = NULL;

void make_empty(void)
{
   struct node *temp;
   while (top) {
      temp = top;
      top = top->next;
      free(temp);
   }
}

bool is_empty(void)
{
   return top == NULL;
}

bool push(int i)
{
   struct node *new_node = malloc(sizeof(struct node));
   if (new_node) {   
      new_node->value = i;
      new_node->next = top;
      top = new_node;

      return true;
   } else {
      return false;
   }
}

int pop(void)
{
   if (is_empty()) {
      printf("*** Stack underflow; program terminated. ***\n");
      exit(EXIT_FAILURE);
   }

   int ret = top->value;
   struct node *prev = top;
   top = top->next;
   free(prev);

   return ret;
}