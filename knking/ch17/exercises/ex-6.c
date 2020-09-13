#include <stdlib.h>

struct node
{
   int value;
   struct node *next;
};

struct node *first = NULL;

struct node *delete_from_list(struct node *list, int n)
{
   struct node *cur = list;
   while (cur->next) {
      if (cur->next->value == n) break;
      cur = cur->next;
   }

   if (cur == list && cur->value == n) { // n is in the first node
      list = list->next;
   }
   if (cur == NULL) {
      return list; // n is not in the list
   } else {
      cur->next = cur->next->next; // n is in some other node
   }

   free(cur->next);
   return list;
}