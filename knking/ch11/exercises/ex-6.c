#include <stdio.h>

void find_two_largest(int a[], int n, int *largest, int *second_largest)
{
   if (a[1] > a[0]) {
      *largest = a[1];
      *second_largest = a[0];
   } else {
      *largest = a[0];
      *second_largest = a[1];
   }

   for (int i = 2; i < n; i++) {
      if (a[i] > *largest) {
         *second_largest = *largest;
         *largest = a[i];
      } else if (a[i] > *second_largest) {
         *second_largest = a[i];
      }
   }
}

// ✔️