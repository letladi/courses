#include <stdio.h>
#include <assert.h>
#include "stackADT.h"

int main(void)
{
   Stack s1, s2;

   s1 = create();
   s2 = create();

   int i = 1, j = 2, k = 3;

   assert(s1 != s2);

   push(s1, &i);
   assert(peek(s1) == &i);
   push(s1, &j);
   assert(peek(s1) == &j);

   assert(length(s1) == 2);

   assert(is_empty(s2));
   assert(!is_empty(s1));

   assert(length(s2) == 0);

   assert(pop(s1) == &j);
   push(s2, &j);
   assert(pop(s1) == &i);

   assert(length(s1) == 0);

   push(s2, &i);
   assert(length(s2) == 2);
   assert(peek(s2) == &i);
   destroy(s1);

   assert(length(s1) == 0);

   while (!is_empty(s2)) pop(s2);

   assert(length(s2) == 0);


   assert(is_empty(s2));

   

   push(s2, &k);
   assert(peek(s2) == &k);
   make_empty(s2);
   assert(is_empty(s2));

   

   int test_list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   for (int i = 0; i < 10; i++) {
      push(s2, &test_list[i]);
   }

   printf("Stack works....\n");

   return 0;
}