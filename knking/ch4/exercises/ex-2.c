/*
   Yes, the value will always be negative and it will be an integer
   with its fractional part (from the division) truncated

*/
#include <stdio.h>

int main(void)
{
   int i = 9, j = 7;
   printf("%d %d\n", (-i)/j, -(i/j));
   return 0;
}