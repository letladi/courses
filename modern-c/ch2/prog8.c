#include <stdio.h>

int main(void)
{
  float balance, interest, monthlyPayment;
  int numMonths = 12.0;

  printf("Enter amount of loan: ");
  scanf("%f", &balance);

  printf("Enter interest rate: ");
  scanf("%f", &interest);
  interest /= 100.0;

  printf("Enter monthly payment: ");
  scanf("%f", &monthlyPayment);

  float monthlyInterest = interest / numMonths;

  balance = balance + (monthlyInterest * balance) - monthlyPayment;
  printf("Balance remaining after first payment: %.2f\n", balance);
  balance = balance + (monthlyInterest * balance) - monthlyPayment;
  printf("Balance remaining after second payment: %.2f\n", balance);
  balance = balance + (monthlyInterest * balance) - monthlyPayment;
  printf("Balance remaining after third payment: %.2f\n", balance);

  return 0;
}
