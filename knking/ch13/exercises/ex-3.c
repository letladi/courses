/**
 * i = 12 ✔️
 * s = abc34 ✔️
 * j = 56 ✔️
*/

#include <stdio.h>

int main(void)
{
   int i, j;
   char s[10];
   scanf("%d%s%d", &i, s, &j);
   printf("i = %d, s = %s, j = %d\n", i, s, j);

   return 0;
}