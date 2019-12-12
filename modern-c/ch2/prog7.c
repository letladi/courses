#include <stdio.h>

int main(void)
{
  int _20_dollar_bills = 0, _10_dollar_bills = 0, _5_dollar_bills = 0, _1_dollar_bills = 0;
  int amount;

  printf("Enter a dollar amount: ");
  scanf("%d", &amount);

  _20_dollar_bills = amount / 20;
  amount -= 20 * _20_dollar_bills;

  _10_dollar_bills = amount / 10;
  amount -= 10 * _10_dollar_bills;

  _5_dollar_bills = amount / 5;
  amount -= 5 * _5_dollar_bills;

  _1_dollar_bills = amount;

  printf("\n$20 bills: %d\n", _20_dollar_bills);
  printf("$10 bills: %d\n", _10_dollar_bills);
  printf("$5 bills: %d\n", _5_dollar_bills);
  printf("$1 bills: %d\n", _1_dollar_bills);

  return 0;
}
