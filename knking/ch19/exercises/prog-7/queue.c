#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

struct node {
   Item data;
   struct node *next;
};

struct queue_type {
   struct node *front;
   struct node *back;

   int count;
};

Queue create_queue(int el_size)
{
   Queue q = malloc(sizeof(struct queue_type));
   q->front = q->back = NULL;
   q->count = 0;
   return q;
}

static bool is_full(Queue q) 
{
   return false;
}

bool enqueue(Queue q, Item s)
{
  bool ret = false;
  struct node *t = malloc(sizeof(struct node));
  if (!t) return ret;

  t->data = s;
  if (queue_is_empty(q)) {
     q->front = q->back = t;
  } else {
     q->back->next = t;
     q->back = t;
  }
  ret = true;
  q->count++;
  return ret;
}

Item dequeue(Queue q) 
{
   Item ret = NULL;
   if (queue_is_empty(q)) return ret;
   else {
      struct node *first = q->front;
      q->front = q->front->next;

      ret = first->data;
      free(first);
      q->count--;
   }
   return ret;
}


Item queue_front(Queue q)
{
   if (queue_is_empty(q)) return NULL;
   return q->front->data;
}

Item queue_back(Queue q)
{
   if (queue_is_empty(q)) return NULL;
   return q->back->data;
}

bool queue_is_empty(Queue q)
{
   return queue_size(q) == 0;
}

void destroy_queue(Queue q)
{
   free(q);
}

size_t queue_size(Queue q)
{
   return q->count;
}
