#include <stdio.h>

int main(void)
{
   int a;
   printf("Enter a 3-digit number: ");
   scanf("%d", &a);
   int a1, a2, a3;
   a3 = a % 10;
   a /= 10;
   a2 = a % 10;
   a1 = a / 10;
   printf("The reversal is: %d%d%d\n", a3, a2, a1);

   return 0;
}