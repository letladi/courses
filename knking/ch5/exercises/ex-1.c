/*
   a) 1 ✔️
   b) 1 ✔️
   c) 1 ✔️
   d) 0 ✔️
*/

#include <stdio.h>

int main(void)
{
   int i, j, k;

   i = 2; j = 3;
   k = i * j == 6;
   printf("a) %d\n", k);

   i = 5; j = 10; k = 1;
   printf("b) %d\n", k > i  < j);

   i = 3; j = 2; k = 1;
   printf("c) %d\n", i < j == j < k);

   i = 3; j = 4; k = 5;
   printf("d) %d\n", i % j + i < k);

   return 0;
}