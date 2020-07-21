#include <stdio.h>

// int sum_array(const int *a, int n)
// {
//    int sum = 0;
//    for (int *p = a; p <= &a[n - 1]; p++) 
//       sum += *p++;
//    return sum;
// }
// ❌ [I still used a[n - 1], instead of a+n-1]. Also using p++ in the body loop and in the loop header results in the wrong computation


int sum_array(const int a[], int n)
{
   int *p, sum;
   sum = 0;
   for (p = a; p < a + n; p++)
      sum += *p;
   return sum;
}

int main(void)
{
   int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9 , 10};
   printf("array_sum = %d\n", sum_array(a, 10));
   return 0;
}
