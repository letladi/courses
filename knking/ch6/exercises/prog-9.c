#include <stdio.h>
#define INTEREST_TIME 12.0

int main(void) 
{
   float loanAmt, interest, monthlyAmt, interestPmt;
   int numPayments;

   printf("Enter amount of loan: ");
   scanf("%f", &loanAmt);
   printf("Enter interest rate: ");
   scanf("%f", &interest);
   interest /= 100.0;

   printf("Enter the number of payments: ");
   scanf("%d", &numPayments);

   float totalInterest = loanAmt * interest / INTEREST_TIME * numPayments;
   loanAmt += totalInterest;
   monthlyAmt = loanAmt / numPayments;

   printf("Monthly payments: $%0.2f\n", monthlyAmt);
   for (int i = 1; i <= numPayments; i++) {
      printf("Balance remaining after payment %d: $%.2f\n", i, (loanAmt -= monthlyAmt));
   }

   return 0;
}