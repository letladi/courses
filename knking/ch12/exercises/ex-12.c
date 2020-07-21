#include <stdio.h>

#define N 7

void find_two_largest(const int *a, int n, int *largest, int *second_largest)
{
   *second_largest = *largest = *a;
   const int *last = a + n - 1;
   for (int i = 1; (a + i) <= last; i++) {
      if (*(a + i) > *largest) {
         *second_largest = *largest;
         *largest = *(a + i);
      } else if (*(a + i) > *second_largest) {
         *second_largest = *(a + i);
      }
   }
}

int main(void)
{
   int largest, second_largest;
   int a[N] = {5, 15, 34, 14, 2, 52, 72};
   find_two_largest(a, N, &largest, &second_largest);
   printf("In a: largest = %d, second largest = %d\n", largest, second_largest);
   int b[2] = {5, 15};
   find_two_largest(b, 2, &largest, &second_largest);
   printf("In b: largest = %d, second largest = %d\n", largest, second_largest);
   int c[1] = {15};
   find_two_largest(c, 1, &largest, &second_largest);
   printf("In c: largest = %d, second largest = %d\n", largest, second_largest);

   return 0;
}
