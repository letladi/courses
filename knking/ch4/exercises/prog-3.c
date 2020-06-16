#include <stdio.h>

int main(void)
{
   int a1, a2, a3;
   printf("Enter a 3-digit number: ");
   scanf("%1d%1d%1d", &a1, &a2, &a3);

   printf("The reversal is: %d%d%d\n", a3, a2, a1);

   return 0;
}