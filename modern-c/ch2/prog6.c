#include <stdio.h>

int main(void)
{
  float x;
  printf("Enter an x value: ");
  scanf("%f", &x);

  float result = ((((3*x + 2)* x - 5)*x - 1)*x + 7)*x - 6;

  printf("Here is the result: %0.1f\n", result);

  return 0;
}
