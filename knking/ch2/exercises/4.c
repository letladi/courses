#include <stdio.h>
#define TAX 0.05f

int main(void)
{
   float amt, finalAmt;
   printf("Enter an amount: ");
   scanf("%f", &amt);

   finalAmt = amt + (amt * TAX);
   printf("With tax added: $%.2f\n", finalAmt);

   return 0;
}