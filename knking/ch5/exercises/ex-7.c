/*
   if i = 17: 17 ✔️
   if i = -17: 17 ✔️
*/

#include <stdio.h>

int main(void)
{
   int i = 17;
   printf("%d\n", i >= 0 ? i : -i);
   i = -17;
   printf("%d\n", i >= 0 ? i : -i);

   return 0;
}