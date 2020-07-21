#include <stdio.h>

#define N 3

int main(void)
{
   double ident[N][N];
   int row, col;
   int count = 0;
   for (double *p = ident[0], *end = ident[0] + (N * N); p < end; p++, count++) {
      *p = count % (N + 1) == 0;
   }

   // ✔️

   printf("%dx%d identity matrix:\n", N, N);
   for (row = 0; row < N; row++) {
      for (col = 0; col < N; col++) {
         printf("%3.0lf", ident[row][col]);
      }
      printf("\n");
   }
   return 0;
}
