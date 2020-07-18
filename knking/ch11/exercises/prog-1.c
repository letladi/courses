#include <stdio.h>

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones)
{
   *twenties = dollars / 20;
   dollars -= *twenties * 20;
   *tens = dollars / 10;
   dollars -= *tens * 10;
   *fives = dollars / 5;
   dollars -= *fives;
   *ones = dollars;
}

int main(void)
{
   printf("Enter a dollar amount: ");
   int amt, q, twenties, tens, fives, ones;
   scanf("%d", &amt);
   pay_amount(amt, &twenties, &tens, &fives, &ones);
   printf("$20 bills: %.0d\n", twenties);
   printf("$10 bills: %d\n", tens);
   printf("$5 bills: %d\n", fives);
   printf("$1 bills: %d\n", ones);

   return 0;
}