/*
   the reassign both the sum and avg pointers to double values
   instead of using the indirection operator to assign values to 
   the variables that they point to.
*/

#include <stdio.h>

void avg_sum(double a[], int n, double *avg, double *sum)
{
   int i;
   *sum = 0.0;
   for (i = 0; i < n; i++) {
      *sum += a[i];
   }
   *avg = *sum / n;
}

int main(void)
{
   int n = 5;
   double nums[] = {100, 200, 300, 400, 500};
   double sum, avg;
   avg_sum(nums, n, &avg, &sum);
   printf("sum = %f\n", sum);
   printf("avg = %f\n", avg);
   return 0;
}