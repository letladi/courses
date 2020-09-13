#include <stdlib.h>
#include <stdio.h>

struct node
{
   int value;
   struct node *next;
};

struct node *first = NULL;

struct node *add_to_list(struct node *list, int n)
{
   struct node *new_node;
   new_node = malloc(sizeof(struct node));
   if (new_node == NULL) {
      printf("Error: malloc failed in add_to_list\n");
      exit(EXIT_FAILURE);
   }
   new_node->value = n;
   new_node->next = list;
   return new_node;
}

struct node *read_numbers(void)
{
   struct node *first = NULL;
   int n;

   printf("Enter a series of integers (0 to terminate): ");
   for (;;) {
      scanf("%d", &n);
      if (n == 0) return first;
      first = add_to_list(first, n);
   }
}

struct node *search_list(struct node *list, int n)
{
   while (list != NULL && list->value != n)
      list = list->next;

   return list;
}

void delete_from_list(struct node **list, int n)
{
   struct node *cur, *prev;
   for (cur = *list, prev = NULL; cur != NULL && cur->value != n; prev = cur, cur = cur->next)
      ;

   // if (cur == NULL) 
   //    return list; // n was not found
   if (prev == NULL) 
      *list = (*list)->next; // n is in the first node
   else 
      prev->next = cur->next; // n is in some other node

   free(cur);
   // return list;
}

void print_list(struct node* list)
{
   while (list) {
      printf("%d ", list->value);
      list = list->next;
   }
   printf("\n");
}

int main(void)
{
   first = add_to_list(first, 1); first = add_to_list(first, 2); first = add_to_list(first, 3); first = add_to_list(first, 4);
   print_list(first);

   return 0;
}