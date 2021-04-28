#include <stdio.h>
#include <assert.h>
#include "stackADT.h"

int main(void)
{
   Stack s1, s2;

   s1 = create();
   s2 = create();

   assert(s1 != s2);

   push(s1, 1);
   assert(peek(s1) == 1);
   push(s1, 2);
   assert(peek(s1) == 2);

   assert(length(s1) == 2);

   assert(is_empty(s2));
   assert(!is_empty(s1));

   assert(length(s2) == 0);

   assert(pop(s1) == 2);
   push(s2, 2);
   assert(pop(s1) == 1);

   assert(length(s1) == 0);

   push(s2, 1);
   assert(length(s2) == 2);
   assert(peek(s2) == 1);
   destroy(s1);

   assert(length(s1) == 0);

   while (!is_empty(s2)) pop(s2);

   assert(length(s2) == 0);


   assert(is_empty(s2));

   

   push(s2, 3);
   assert(peek(s2) == 3);
   printf("We are here\n");
   make_empty(s2);
   // printf("We are here\n");
   assert(is_empty(s2));

   

   Item test_list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   for (int i = 0; i < 10; i++) {
      push(s2, test_list[i]);
   }

   printf("Stack works....\n");

   return 0;
}