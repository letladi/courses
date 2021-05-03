#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stddef.h>

#define ARRAY_LEN 3

typedef void *Item;
typedef struct queue_type *Queue;


Queue create_queue(int el_size);
bool enqueue(Queue q, Item s);
Item dequeue(Queue q);
Item queue_front(Queue q);
Item queue_back(Queue q);
bool queue_is_empty(Queue q);
void destroy_queue(Queue q);
size_t queue_size(Queue q);

#endif