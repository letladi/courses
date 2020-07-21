#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <stdio.h>

#define R 7
#define C 24

bool search(const int a[], int n, int key)
{
   const int *last = a + n - 1;
   for (int *p = a; p <= last; p++) {
      if (*p == key) return true;
   }
   return false;
}

int main(void)
{
   srand(time(NULL));
   int temperatures[R][C];
   for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
         temperatures[i][j] = (0 + rand()) % 100;
         printf("%3d ", temperatures[i][j]);
      }
      printf("\n");
   }
   // answer
   bool found = search(&temperatures[0][0], R * C, 32);
   printf("The matrix contains 32? ");
   printf(found ? "Yes.\n" : "No.\n");
   return 0;   
}