#include <stdio.h>
#include <stdlib.h>
#include "../ex-1/queue.h"

int main(void)
{
   Queue q = create_queue(sizeof(int));
   int i = 1;

   printf("queue size: %zu\n", queue_size(q));

   enqueue(q, &i);
   if (!queue_is_empty(q)) printf("the queue is not empty\n");
   
   int j = 2;
   enqueue(q, &j);
   
   int k = 3;
   enqueue(q, &k);

   printf("queue size: %zu\n", queue_size(q));

   int *b = queue_front(q);   
   printf("front: %d\n", *b);
   int *a = queue_back(q);
   printf("back:  %d\n", *a);
   

   printf("queue size: %zu\n", queue_size(q));

   dequeue(q);

   a = queue_back(q);
   b = queue_front(q);

   printf("front:  %d\n", *a);
   printf("back: %d\n", *b);

   dequeue(q);dequeue(q);

   if (!dequeue(q)) printf("NULL is returned if there are no elements in the queue.\n");

   printf("queue size: %zu\n", queue_size(q));

   destroy_queue(q);

   return 0;
}