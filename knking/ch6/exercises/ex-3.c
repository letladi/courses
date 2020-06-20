/*
   5 3 1 ❌ 5 4 3 2
*/

#include <stdio.h>

int main(void)
{
   for (int i = 5, j = i - 1; i > 0, j > 0; --i, j = i - 1)
      printf("%d ", i);

   return 0;
}