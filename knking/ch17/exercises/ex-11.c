struct node {
   int value; 
   struct node* next;
};

int count_occurrences(struct node* list, int n)
{
   int count = 0;
   while (list) {
      if (list->value == n) count++;
      list = list->next;
   }
   return count;
}