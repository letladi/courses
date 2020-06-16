/*
   a) 0 2 ✔️
   b) 4 11 6 ✔️
   c) 0 8 7 ✔️
   d) 4 4 5 4 ❌ 3 4 5 4
*/

#include <stdio.h>

int main(void)
{
   int i, j, k;
   // a)
   i = 1;
   printf("%d ", i++ - 1);
   printf("%d\n", i);
   // b)
   i = 10; j = 5;
   printf("%d ", i++ - ++j);
   printf("%d %d\n", i, j);
   // c)
   i = 7; j = 8;
   printf("%d ", i++ - --j);
   printf("%d %d\n", i, j);
   // d)
   i = 3; j = 4; k = 5;
   printf("%d ", i++ - j++ + --k);
   printf("%d %d %d\n", i, j, k);

   return 0;
}
