/*
   a) i = 3, j = 2 ✔️
   b) i = 0, j = 2 ✔️
   c) i = 1, j = 2 ✔️
   d) i = 1, j = 3 ✔️
*/

#include <stdio.h>

int main(void)
{
   int i, j;
   i = 1, j = 2;
   i += j;
   printf("a) i = %d, j = %d\n", i, j);
   i = 1, j = 2;
   i--;
   printf("b) i = %d, j = %d\n", i, j);
   i = 1, j = 2;
   i * j / i;
   printf("c) i = %d, j = %d\n", i, j);
   i = 1, j = 2;
   i % ++j;
   printf("d) i = %d, j = %d\n", i, j);

   return 0;
}