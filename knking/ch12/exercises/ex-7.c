#include <stdio.h>
#include <stdbool.h>

#define N 10

bool search(const int a[], int n, int key)
{
   for (int *p = a, *last = a + n - 1; p <= last; p++) {
      if (*p == key) return true;
   }
   return false;
}

int main(void)
{
   int a[N] = {65, 16, 22, 10, 5, 3, 88, 46, 79, 59};
   int b[N] = {14, 16, 15, 44, 85};

   printf("found 88 in first array? ");
   printf(search(a, N, 88) ? "Yes": "No");
   printf("\nFound 0 in second array? ");
   printf(search(b, N, 0) ? "Yes" : "No");
   printf("\n");
   return 0;
}