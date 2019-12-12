#include <stdio.h>

float mult(float, int);

int main(void)
{
  float x;
  printf("Enter an x value: ");
  scanf("%f", &x);

  float result = (3 * mult(x, 5)) + (2 * mult(x, 4)) - (5 * mult(x, 3))
    - mult(x, 2) + (7 * mult(x, 1)) - 6;

  printf("Here is the result: %f\n", result);

  return 0;
}

float mult(float x, int n) {
  float res = 1.0;
  while (n--) {
    res *= x;
  }
  return res;
}
