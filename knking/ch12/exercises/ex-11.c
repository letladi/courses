#include <stdio.h>

#define N 8

int find_largest(int a[], int n)
{
   int *p = a;
   int max = *p;
   for (int *last = a + n - 1; p <= last; p++) 
      if(*p > max) max = *p;
   return max;
}

int main(void)
{
   int a[N] = {5, 115, 34, 54, 14, 2, 52, 72};
   printf("largest = %d\n", find_largest(a, N));
   return 0;
}