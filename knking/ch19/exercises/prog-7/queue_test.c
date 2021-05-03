#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"

int main(void)
{
   Queue q = create_queue(sizeof(int));

   assert(queue_size(q) == 0);
   assert(queue_is_empty(q));
   assert(!queue_front(q));
   assert(!queue_back(q));

   int i = 1;

   enqueue(q, &i);
   assert(!queue_is_empty(q));
   assert(queue_size(q) == 1);

   
   int j = 2;
   enqueue(q, &j);
   assert(queue_size(q) == 2);
   
   int k = 3;
   enqueue(q, &k);

   assert(queue_size(q) == 3);

   assert(queue_front(q) == &i);
   assert(queue_back(q) == &k);

   int *b = queue_front(q);   
   assert(b == &i);
   int *a = queue_back(q);
   assert(a == &k);
   
   dequeue(q);
   assert(queue_size(q) == 2);

   assert(queue_front(q) == &j);

   dequeue(q);
   assert(queue_size(q) == 1);
   dequeue(q);
   assert(queue_size(q) == 0);
   assert(queue_is_empty(q));


   printf("Queue is working...\n");

   return 0;
}