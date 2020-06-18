/*
   a) 1 3 4 5 ✔️
   b) 0 7 8 9 ✔️
   c) 1 7 8 9 ❌ 1 8 8 9
   d) 1 2 1 1 ✔️
*/

#include <stdio.h>

int main(void)
{
   int i, j, k;

   i = 3; j = 4; k = 5;
   printf("a) %d ", i < j || ++j < k);
   printf("%d %d %d\n", i, j, k);

   i = 7; j = 8; k = 9;
   printf("b) %d ", i - 7 && j++ < k);
   printf("%d %d %d\n", i, j, k);

   i = 7; j = 8; k = 9;
   printf("c) %d ", (i = j) || (j = k));
   printf("%d %d %d\n", i, j, k);

   i = 1; j = 1; k = 1;
   printf("d) %d ", ++i || ++j && ++k);
   printf("%d %d %d\n", i, j, k);

   return 0;
}