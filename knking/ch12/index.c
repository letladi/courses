#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NUM_ROWS 5
#define NUM_COLS 4

int find_largest(int a[], int n)
{
   int max = a[0];
   for (int i  = 1; i < n; i++) {
      if (i[a] > max) max = a[i];
   }
   return max;
}

int main(void)
{  
   srand(time(NULL));
   int a[NUM_ROWS][NUM_COLS] = {};
   int *p;

   printf("array before randomization: \n");
   int i = 1;
   for (p = a[0]; p <= &a[NUM_ROWS - 1][NUM_COLS - 1]; p++, i++) {
      printf("%4d ", *p);
      if (i % NUM_COLS == 0) {
         printf("\n");
      }
   }
   printf("\n");

   for (p = a[0]; p <= &a[NUM_ROWS - 1][NUM_COLS - 1]; p++) {
      *p = 0 +  rand() % 100;
   }

   printf("random array elements: \n");
   i = 1;
   for (p = a[0]; p <= &a[NUM_ROWS - 1][NUM_COLS - 1]; p++, i++) {
      printf("%4d ", *p);
      if (i % NUM_COLS == 0) {
         printf("\n");
      }
   }
   printf("\n");
   printf("largest elements = %d\n", find_largest(a[0], NUM_ROWS * NUM_COLS));

   int r = 2;
   for (p = a[r]; p < a[r] + NUM_COLS; p++) 
      *p = 0;

   int c = 3;
   int (*q)[NUM_COLS];
   for (q = &a[0]; q <= &a[NUM_ROWS - 1]; q++) {
      (*q)[c] = 0;
   }

   printf("\narray after reset: \n");
   i = 1;
   for (p = a[0]; p <= &a[NUM_ROWS - 1][NUM_COLS - 1]; p++, i++) {
      printf("%3d ", *p);
      if (i % NUM_COLS == 0) printf("\n");
   }
   printf("\n");
   
   return 0;
}