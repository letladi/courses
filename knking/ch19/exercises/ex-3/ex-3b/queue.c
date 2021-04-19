#include <stdlib.h>
#include "../../ex-1/queue.h"

struct node {
   Item data;
   struct node *next;
};

struct queue_type {
   struct node *front;
   struct node *back;
};

static struct node* create_node(Item s)
{
   struct node* ret = malloc(sizeof(struct node));
   ret->data = s;
   ret->next = NULL;
   return ret;
}

Queue create_queue(int size)
{
   Queue ret = malloc(sizeof(struct queue_type));
   if (!ret) return ret;
   else {
      ret->front = NULL;
      ret->back = NULL;
   }
   return ret;
}

bool queue_is_empty(Queue q)
{
   return (q->front == NULL) && (q->back == NULL);
}

bool enqueue(Queue q, Item s)
{
   struct node *new_node = create_node(s);
   if (!new_node) return false;

   if (queue_is_empty(q)) {
      q->front = new_node;
      q->back = new_node;
   } else {
      q->back->next = new_node;
      q->back = new_node;
   }
   return true;
}

Item dequeue(Queue q)
{
   struct node *first = q->front;
   if (first) {
      q->front = q->front->next;
      Item ret_item = first->data;
      free(first);
      return ret_item;
   } else {
      return first;
   }
   
}

Item queue_front(Queue q)
{
   return q->front->data;
}

Item queue_back(Queue q)
{
   return q->back->data;
}

void destroy_queue(Queue q)
{
   struct node *nd = q->front;
   struct node *prev = NULL;
   while (nd) {
      prev = nd;
      nd = nd->next;
      free(prev);
   }
   free(q);
}

size_t queue_size(Queue q)
{
   struct node *nd = q->front;
   size_t count = 0;
   while (nd) {
      count++;
      nd = nd->next;
   }
   return count;
}