#include <stdio.h>

int main(void)
{
   int m, n;
   printf("Enter two integers: ");
   scanf("%d %d", &m, &n);

   while (n > 0) {
      int temp = n;
      n = m % n;
      m = temp;
   }
   printf("Greatest common divisor: %d\n", m);

   return 0;
}