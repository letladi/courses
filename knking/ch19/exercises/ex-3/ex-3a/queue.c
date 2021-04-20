#include <stdlib.h>
#include "../../ex-1/queue.h"

#define INCR_VAL 5

struct queue_type {
   Item *list;
   int top;
   int next;
   int size;
   int count;
};

Queue create_queue(int el_size)
{
   Queue q = malloc(sizeof(struct queue_type));
   q->top = q->next = 0;
   q->list = malloc(el_size * INCR_VAL);
   if (q->list) q->size = INCR_VAL;
   return q;
}

bool enqueue(Queue q, Item s)
{
   bool ret;
   if ((q->top == q->next) && (q->top == 0)) { // q is still empty
      q->list[q->next++] = s;
      ret = true;
   } else if ((q->top < q->next) && (q->next < q->size)) {
      q->list[q->next++] = s;
      ret = true;
   } else if ((q->top < q->next) && (q->next == q->size)) {
      q->next = 0;
      q->list[q->next++] = s;
      ret = true;
   } else if (q->top > q->next) { // we have already wrapped the insertions
      q->list[q->next++] = s;
      ret = true;
   } else if ((q->top == q->next) && (q->top > 0)) { // we must increase the size of the queue
      int new_size = (q->size * sizeof(*q->list)) + (sizeof(*q->list) * INCR_VAL);
      Item *new_list = realloc(q->list, new_size);
      if (new_list) {
         q->list= new_list;
         // move items from 'top' 'to the last index'
         int j = new_size;
         while (q->size >= q->top) {
            q->list[--j] = q->list[--q->size];
         }
         q->top = q->size + 1;
         q->size = new_size;
         q->list[q->next++] = s;
         ret = true;
      } else {
         ret = false;
      }
   } else if ((q->next == q->size) && q->top == 0) {
      int new_size = (q->size * sizeof(*q->list)) + (sizeof(*q->list) * INCR_VAL);
      Item *new_list = realloc(q->list, new_size);
      if (new_list) {
         q->list = new_list;
         q->size = new_size;
         q->list[q->next++] = s;
         ret = true;
      } else {
         ret = false;
      }
   }

   if (ret) q->count++;

   return ret;
}

Item dequeue(Queue q) 
{
   Item ret = NULL;
   if (q->count > 0) {
      ret = q->list[q->top++];
      if (q->top ==q->size) q->top = 0;
      q->count--;
   } 
   return ret;
}


Item queue_front(Queue q)
{
   return q->list[q->top];
}

Item queue_back(Queue q)
{
   return q->list[q->next - 1];
}

bool queue_is_empty(Queue q)
{
   return (q->top == 0) && (q->top == q->next);
}

void destroy_queue(Queue q)
{
   free(q);
}

size_t queue_size(Queue q)
{
   return q->count;
}
