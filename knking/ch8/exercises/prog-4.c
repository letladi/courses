#include <stdio.h>
#define N 10

int main(void)
{
   int a[N], i;
   int len = (int) (sizeof(a) / sizeof(a[0]));
   printf("Enter %d numbers: ", N);
   for (i = 0; i < len; i++) {
      scanf("%d", &a[i]);
   }

   printf("In reverse order: ");
   for (i = len - 1; i >= 0; i--) printf(" %d", a[i]);
   printf("\n");

   return 0;
}