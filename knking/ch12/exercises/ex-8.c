#include <stdio.h>

#define N 10

void store_zeros(int a[], int n)
{
   for (int *p = a; p < (a + n); p++)
      *p = 0;
}

// ✔️

int main(void)
{
   int a[N] = {25, 53, 16, 5, 17, 39, 69, 88, 11, 7};
   printf("Before: ");
   for (int i = 0; i < N; i++) printf("%3d ", a[i]);
   printf("\nAfter:  ");
   store_zeros(a, N);
   for (int j = 0; j < N; j++) printf("%3d ", a[j]);
   printf("\n"); 
   return 0;
}