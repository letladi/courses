/*
   a) 63 8 ✔️
   b) 3 2 1 ✔️
   c) 2 -1 3 ✔️
   d) 0 0 0 ✔️
*/

#include <stdio.h>

int main(void)
{
   // a)
   int i, j, k;
   i = 7; j = 8;
   i *= j + 1;
   printf("%d %d\n", i, j);
   // b)
   i = j = k = 1;
   i += j += k;
   printf("%d %d %d\n", i, j, k);
   // c)
   i = 1; j = 2; k = 3;
   i -= j -= k;
   printf("%d %d %d\n", i, j, k);
   // d)
   i = 2; j = 1; k = 0;
   i *= j *= k;
   printf("%d %d %d\n", i, j, k);
}