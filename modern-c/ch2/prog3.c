#include <stdio.h>

int main(void)
{
  float amount;
  printf("Enter an amount: ");
  scanf("%f", &amount);

  float total = amount + (amount * 0.05);

  printf("With tax added: %.2f\n", total);

  return 0;
}
