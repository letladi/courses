/*
   a) 3 ✔️
   b) -3 ✔️
   c) 3 ✔️
   d) -3 ✔️ 
*/

#include <stdio.h>

int main(void)
{
   printf("a) %d\n", 8 % 5);
   printf("b) %d\n", -8 % 5);
   printf("c) %d\n", 8 % -5);
   printf("d) %d\n", -8 % -5);

   return 0;
}