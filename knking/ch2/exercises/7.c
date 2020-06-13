#include <stdio.h>

int main(void)
{
   printf("Enter a dollar amount: ");
   int amt, q;
   scanf("%d", &amt);
   q = amt / 20;
   printf("$20 bills: %.0d\n", q);
   amt -= q * 20;
   q = amt / 10;
   printf("$10 bills: %d\n", q);
   amt -= q * 10;
   q = amt / 5;
   printf("$5 bills: %d\n", q);
   amt -= q;
   printf("$1 bills: %d\n", amt);

   return 0;
}