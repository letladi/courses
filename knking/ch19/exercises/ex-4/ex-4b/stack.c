#include <stdlib.h>
#include "../stack.h"

struct node {
   Item data;
   struct node* next;
};

struct stack_type {
   struct node *top;
   size_t elSize;
};

Stack create(size_t elSize)
{
   Stack ret = malloc(sizeof(struct stack_type));
   if (!ret) return NULL;
   ret->top = NULL;
   ret->elSize = elSize;
   return ret;
}

void destroy(Stack s)
{
   struct node* cur = s->top;
   struct node* prev;
   while (cur) {
      prev = cur;
      cur = cur->next;
      free(prev);
   }
   free(s);
}

void make_empty(Stack s)
{
   struct node* cur = s->top;
   struct node* prev;
   while (cur) {
      prev = cur;
      cur = cur->next;
      free(prev);
   }
   s->top = NULL;
}

bool is_empty(Stack s)
{
   return s->top == NULL;
}

bool push(Stack s, Item i)
{
   struct node* item = malloc(sizeof(struct node));
   if (!item) return false;
   
   item->data = i;
   if (is_empty(s)) {
      s->top = item;
      item->next = NULL;
      return true;
   } else {
      item->data = i;
      item->next = s->top;
      s->top = item;

      return true;
   }
}

Item pop(Stack s)
{
   if (is_empty(s)) return NULL;

   struct node* item = s->top;
   s->top = s->top->next;
   Item ret = item->data;
   free(item);
   return ret;
}

Item top(Stack s)
{
   if (is_empty(s)) return NULL;
   return s->top->data; 
}

bool is_full(Stack s)
{
   return false;
}

