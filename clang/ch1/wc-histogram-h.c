#include <stdio.h>
#define TEN_PLUS_INDEX 0
#define MAX_COUNTABLE 10

int main()
{
   int c;
   int wordc[MAX_COUNTABLE];

   for (int i = 0; i < MAX_COUNTABLE; i++) wordc[i] = 0;

   int nc = 0;
   while ((c = getchar()) != EOF) {
      if (c == ' ' || c == '\t' || c == '\n') {
         if (nc) {
            int index = (nc >= MAX_COUNTABLE) ? TEN_PLUS_INDEX : nc;
            ++wordc[index];
         }
         nc = 0;
      } else {
         nc++;
      }
   }

   printf("\nWORD LENGHTS:\n");
   for (int i = 0; i < MAX_COUNTABLE; i++) {
      if (i == TEN_PLUS_INDEX) {
         printf("10+: ");
      } else {
         printf("%d  : ", i);
      }

      for (int j = 0, len = wordc[i]; j < len; j++) {
         printf("|");
      }
      printf("\n");
   }
}
