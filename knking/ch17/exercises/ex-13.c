/**
 * This function fails if we're inserting into an empty list.
 */

#include <stdlib.h>

struct node {
   int value;
   struct node* next;
};

// more correct version
struct node *insert_into_ordered_list(struct node *list, struct node *new_node)
{
   struct node *cur = list, *prev = NULL;
   while (cur->value <= new_node->value) {
      prev = cur;
      cur = cur->next;
   }
   prev->next = new_node;
   new_node->next = cur;
   return list;
}