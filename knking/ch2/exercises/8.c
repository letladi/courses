#include <stdio.h>

int main(void) 
{
   float loanAmt, interest, monthlyAmt, interestPmt;

   printf("Enter amount of loan: ");
   scanf("%f", &loanAmt);
   printf("Enter interest rate: ");
   scanf("%f", &interest);
   interest /= 100.0;
   printf("Enter monthly payment: ");
   scanf("%f", &monthlyAmt);

   interestPmt = loanAmt * interest / 12.0;
   loanAmt = loanAmt + interestPmt - monthlyAmt;
   printf("Balance remaining after first payment: $%0.2f\n", loanAmt);

   interestPmt = loanAmt * interest / 12.0;
   loanAmt = loanAmt + interestPmt - monthlyAmt;
   printf("Balance remaining after second payment: $%0.2f\n", loanAmt);

   interestPmt = loanAmt * interest / 12.0;
   loanAmt = loanAmt + interestPmt - monthlyAmt;
   printf("Balance remaining after third payment: $%0.2f\n", loanAmt);

   return 0;
}