/*
   i = 10
   x = 0.3
   j = 5
   ✔️
*/

#include <stdio.h>

int main(void)
{
   int i, j;
   float x;

   scanf("%d%f%d", &i, &x, &j);
   printf("i = %d, x = %f, j = %d", i, x, j);

   return 0;
}