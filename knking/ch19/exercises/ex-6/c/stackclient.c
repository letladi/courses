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

   assert(is_empty(s2));
   assert(!is_empty(s1));

   assert(pop(s1) == 2);
   push(s2, 2);
   assert(pop(s1) == 1);

   push(s2, 1);
   assert(peek(s2) == 1);
   destroy(s1);

   while (!is_empty(s2)) pop(s2);

   assert(is_empty(s2));

   push(s2, 3);
   assert(peek(s2) == 3);
   make_empty(s2);
   assert(is_empty(s2));

   printf("Stack works....\n");

   return 0;
}