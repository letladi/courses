/**
 * {10, 9, 8, 7, 6, 5, 4, 3, 2, 1} ✔️
 */
#include <stdio.h>

#define N 10

int main(void)
{
   int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   int *p = &a[0], *q = &a[N - 1], temp;
   
   while (p < q) {
      temp = *p;
      *p++ = *q;
      *q-- = temp;
   }

   for (int i = 0; i < N; i++) printf("%d ", a[i]);
   printf("\n");

   return 0;
}