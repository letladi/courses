#include <stdio.h>
#include <limits.h>
#define TEN_PLUS_INDEX 0
#define MAX_COUNTABLE 10

int main()
{
   int c;
   int wordc[MAX_COUNTABLE];

   for (int i = 0; i < MAX_COUNTABLE; i++) wordc[i] = 0;

   int nc = 0;
   int max = INT_MIN;
   while ((c = getchar()) != EOF) {
      if (c == ' ' || c == '\t' || c == '\n') {
         if (nc) {
            int index = (nc >= MAX_COUNTABLE) ? TEN_PLUS_INDEX : nc;
            ++wordc[index];
            if (max < nc) max = nc;
         }
         nc = 0;
      } else {
         nc++;
      }
   }

   printf("\n\tWORD LENGHTS\n");
   while (max) {
      for (int i = 0; i < MAX_COUNTABLE; i++) {
         if (wordc[i] >= max) {
            printf(" - ");
            wordc[i]--;
         }
      }
      max--;
      printf("\n");
   }
   printf("\n");
   for (int i = 0; i < MAX_COUNTABLE; i++) {
      if (i == TEN_PLUS_INDEX) {
         printf("10+");
      } else {
         printf(" %d ", i);
      }
   }
   printf("\n");
}
