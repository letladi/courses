#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

struct queue_type {
   Item *list;

   int top;
   int next;
   int size;
   int count;

   int default_size;
};

Queue create_queue(int el_size)
{
   Item *list = malloc(sizeof(Item) * el_size);
   if (list) {
      Queue q = malloc(sizeof(struct queue_type));
      q->list = list;
      q->top = q->next = q->count = 0;
      q->size = el_size;
      q->default_size = el_size;
      return q;
   } else {
      return NULL;
   }
}

static bool is_full(Queue q) 
{
   if (q->next > q->top) {
      return (q->next - q->top) == (q->size - 1);
   } else {
      return q->next == (q->top - 1);
   }
}

bool enqueue(Queue q, Item s)
{
   bool ret = false;
   if (is_full(q)) {
      int new_len = q->size + q->default_size;

      Item new_list = realloc(q->list, sizeof(Item) * new_len);
      if (new_list) {
         q->list = new_list;
         q->size = new_len;
         return enqueue(q, s);
      } else {
         ret = false;
      }
   } else if (queue_is_empty(q)) {
      q->list[q->next++] = s;
      ret = true;
   } else if (q->next > q->top) {
      if (q->next <= (q->size - 1)) {
         q->list[q->next++] = s;
         ret = true;
      } else if (q->next == (q->size - 1)) {
         if (q->top > 0) {
            q->next = 0;
            q->list[q->next++] = s;
            ret = true;
         }
      }
   } else if (q->next < q->top) {
      q->list[q->next++] = s;
      ret = true;
   }

   if (ret) {
      q->count++;
   }
   return ret;
}

Item dequeue(Queue q) 
{
   Item ret = NULL;
   if (q->count > 0) {
      ret = q->list[q->top++];
      if (q->top == q->size) {
         q->top = 0;
      }
      q->count--;

      // reduce size if the count of items is twice less than the size
      if ((q->size - q->count) > q->default_size) {
         size_t new_potential_size = q->size - q->default_size;
         Item *new_list = realloc(q->list, sizeof(Item) * new_potential_size);
         if (new_list) {
            q->list = new_list;
            q->size = new_potential_size;
         }
      }
   } 
   
   return ret;
}


Item queue_front(Queue q)
{
   if (queue_is_empty(q)) return NULL;
   return q->list[q->top];
}

Item queue_back(Queue q)
{
   if (queue_is_empty(q)) return NULL;
   return q->list[q->next - 1];
}

bool queue_is_empty(Queue q)
{
   return queue_size(q) == 0;
}

void destroy_queue(Queue q)
{
   free(q->list);
   free(q);
}

size_t queue_size(Queue q)
{
   return q->count;
}
