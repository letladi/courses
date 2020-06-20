/*
   15 ❌ 20
   we add the even numbers instead of the odd numbers as I had thought.
   That being said my sum was incorrect even for the odd numbers.
*/

#include <stdio.h>

int main(void)
{
   int sum = 0;
   for (int i = 0; i < 10; i++) {
      if (i % 2) continue;
      sum += i;
   }
   printf("\n");
   printf("%d\n", sum);

   return 0;
}