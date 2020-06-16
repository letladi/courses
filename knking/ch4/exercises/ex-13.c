/*
   ++i
   (i += 1); has the same value as the value of (i + 1), which 
   is the same as ++i, while i++ has the same value as i. ✔️
*/

#include <stdio.h>

int main(void)
{
   int i = 1;
   printf("i++ = %d\n", i++);
   i = 1;
   printf("++i = %d\n", ++i);
   i = 1;
   printf("(i+=1); = %d\n", (i+=1));

   return 0;
}