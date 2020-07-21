#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <stdio.h>

#define R 7
#define C 24

int main(void)
{
   srand(time(NULL));
   int temperatures[R][C];
   printf("MATRIX:\n");
   for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
         temperatures[i][j] = (0 + rand()) % 100;
         printf("%3d ", temperatures[i][j]);
      }
      printf("\n");
   }
   // answer ✔️
   int row_to_print = rand() % R;

   printf("Row %d:\n", row_to_print);
   for (int * p = temperatures[row_to_print], *end = temperatures[row_to_print] + C; p < end; p++) {
      printf("%3d ",*p);
   }
   printf("\n");

   return 0;   
}