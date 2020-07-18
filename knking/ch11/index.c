#include <stdio.h>

void decompose(double x, long *int_part, double *frac_part)
{
   *int_part = (long) x;
   *frac_part = x - *int_part;
}

int main(void)
{
   printf("%.2d\n", 100);
   return 0;
}