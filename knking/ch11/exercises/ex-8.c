#include <stdio.h>

int *find_largest(int a[], int n)
{
   int *largest = &a[0];
   for (int i = 1; i < n; i++) {
      if (a[i] > *largest) largest = &a[i];
   }
   return largest;
}

int main(void)
{
   int a[10] = { 20, 5, 56, 89, 6, 66, 76, 10, -10, 37 };
   printf("largest = %d\n", *find_largest(a, 10));
}

// ✔️