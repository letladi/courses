#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <stdio.h>

#define R 7
#define C 24

void print_day(int n)
{
   switch(n) {
      case 0: printf("Sun  "); break;
      case 1: printf("Mon  "); break;
      case 2: printf("Tues "); break;
      case 3: printf("Wed  "); break;
      case 4: printf("Thur "); break;
      case 5: printf("Fri  "); break;
      case 6: printf("Sat  "); break;
   }
}

int find_largest(int a[], int n)
{
   int *p = a;
   int max = *p;
   for (int *last = a + n - 1; p <= last; p++) 
      if(*p > max) max = *p;
   return max;
}

int main(void)
{
   srand(time(NULL));
   int temperatures[R][C];

   printf("TEMPERATURES:\n");
   for (int i = 0; i < R; i++) print_day(i);
   printf("\n");
   for (int i = 0; i < C; i++) {
      for (int j = 0; j < R; j++) {
         temperatures[j][i] = (0 + rand()) % 100;
         printf("%-5d", temperatures[j][i]);
      }
      printf("\n");
   }

   int max;
   printf("\nMAXIMUM:\n");
   for (int i = 0; i < R; i++) print_day(i);
   printf("\n");
   for (int *p = temperatures[0], *end = temperatures[0] + R, i = 0; i < R; i++) {
      max = find_largest(&temperatures[i][0], C);
      printf("%-5d", max);
   }
   printf("\n");
   
   return 0;   
}