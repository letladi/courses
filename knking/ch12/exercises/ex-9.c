#include <stdio.h>

#define N 4

double inner_product(const double *a, const double *b, int n)
{
   double ret = 0.0;
   for (double *i = a, *j = b, *last = a + n - 1; i <= last; i++, j++)
      ret += (*i)*(*j);

   return ret;
}

int main(void)
{
   double a[N] = {2, 4, 6, 8};
   double b[N] = {1, 3, 5, 7};
   printf("inner_product = %lf\n", inner_product(a, b, N));
   return 0;
}