#include <stdio.h>

int main(void)
{
   int n, digits;
   printf("Enter a number: ");
   scanf("%d", &n);

   if (n < 10)  digits = 1;
   else if (n < 100) digits = 2;
   else if (n < 1000) digits = 3;
   else digits = 4;

   if (digits == 1) {
      printf("The number %d has %d digit\n", n, digits);
   } else {
      printf("The number %d has %d digits\n", n, digits);
   }

   return 0;
}