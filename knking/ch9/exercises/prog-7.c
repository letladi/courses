#include <stdio.h>

double power(int x, int n)
{
   if (n == 0) 
      return 1;
   if (n % 2 == 0) 
      return power(x, n / 2) * power(x, n / 2);
   else 
      return x * power(x, n - 1);
}

int main(void)
{
   printf("2^2 = %f\n", power(2,2));
   printf("2^3 = %f\n", power(2, 3));
   printf("2^4 = %f\n", power(2, 4));
   return 0;
}