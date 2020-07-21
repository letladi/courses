#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define R 3
#define LEN 3
#define MAX_VAL 100

int sum_two_dimensional_array(const int a[][LEN], int n)
{
   int sum = 0;
   for (int *p = &a[0][0], *end = &a[0][0] + (n * LEN); p < end; p++) {
      sum += *p;
   }
   return sum;
}

int main(void)
{
   srand(time(NULL));
   int a[R][LEN];
   for (int *i = &a[0][0], *end = &a[0][0] + (R * LEN), count = 1; i < end; i++, count++) {
      *i = (0 + rand()) % MAX_VAL;
      printf("%-3d ", *i);
      if (count % LEN == 0) printf("\n");
   }

   printf("Total: %d\n", sum_two_dimensional_array(a, R));

   return 0;
}