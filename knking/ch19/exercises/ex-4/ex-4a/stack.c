#include <stdlib.h>

#include "../stack.h"

#define INCR 5

struct stack_type {
   int size;
   int top;
   size_t elSize;
   Item *list;
};

Stack create(size_t elSize)
{
   struct stack_type *ret = malloc(sizeof(struct stack_type));

   if (!ret) return NULL;

   ret->list = malloc(INCR * sizeof(elSize));
   if (ret->list) {
      ret->size = INCR;
      ret->top = -1;
      ret->elSize = elSize;
      return ret;
   } else {
      return NULL;
   }
}

void destroy(Stack s)
{
   free(s->list);
   free(s);
}

void make_empty(Stack s)
{
   Item *new_list = realloc(s->list, INCR * sizeof(s->elSize));
   if (new_list) {
      s->list = new_list;
      s->size = INCR;
   }
   s->top = -1;
}

bool is_empty(Stack s)
{
   return s->top < 0;
}

bool is_full(Stack s)
{
   return s->top == (s->size - 1);
}

bool push(Stack s, Item i)
{
   if (is_empty(s)) s->top = -1;
   if (is_full(s)) {
      Item *new_list = realloc(s->list, sizeof(s->elSize) * (INCR + s->size));
      if (new_list) {
         s->list = new_list;
      } else {
         return false;
      }
   }

   s->list[++s->top] = i;
   return true;
}

Item pop(Stack s)
{
   if (is_empty(s)) return NULL;

   Item ret = s->list[s->top--];
   if ((s->size - s->top) > INCR && ((s->size - INCR) > INCR)) {
      Item* new_list = realloc(s->list, sizeof(s->elSize) * (s->size - INCR));
      if (new_list) s->list = new_list;
   }
   return ret;
}

Item top(Stack s)
{
   if (is_empty(s)) return NULL;
   return s->list[s->top];
}


