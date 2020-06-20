/*
   for (int i = 10; i >= 1; i /= 2) printf("%d ", i++);
   i = 10;
   while (i >= 1) {
      printf("%d ", i++);
      i /= 2;
   }
   ✔️
*/

#include <stdio.h>

int main(void)
{
   int i = 10;
   while (i >= 1) {
      printf("%d ", i++);
      i /= 2;
   }
}