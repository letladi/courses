#include <stdio.h>
#include <stdbool.h>

#define LEN_MAX 100

void selection_sort(int a[], int n) {
   if (n > 1) {
      int max_i = 0;
      int last = a[n - 1];
      for (int i = 1; i < n; i++) {
         if (a[i] > a[max_i]) max_i = i;
      }
      a[n - 1] = a[max_i];
      a[max_i] = last;
      selection_sort(a, n - 1);
   }
}
int main(void)
{
   int n, count = 0;
   int a[LEN_MAX];
   printf("Please enter some integers (-999 to exit): ");
   do {
      scanf(" %d", &n);
      if (n == -999) break;
      a[count++] = n;
   } while (true);

   selection_sort(a, count);

   for (int i = 0; i < count; i++) {
      printf("%d ", a[i]);
   }
   printf("\n");

   return 0;
}