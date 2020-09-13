#include <stdlib.h>

struct node {
   int value; 
   struct node* next;
};

struct node *find_last(struct node *list, int n)
{
   struct node *ret = NULL;
   while (list) {
      if (list->value == n) {
         ret = list;
      }
      list = list->next;
   }

   return ret;
}