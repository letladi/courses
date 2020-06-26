#include <stdio.h>
#define PAUSE_ITERATION 24

int main(void)
{
   int i, n, iteration_count;
   char c;
   printf("This program prints a table of squares.\n");
   printf("Enter number of entries in table: ");
   scanf("%d", &n);
   getchar();

   for (i = 1, iteration_count = 1; i <= n; i++, iteration_count++) {
      if (iteration_count == PAUSE_ITERATION) {
         printf("Press Enter to continue... ");
         while ((c = getchar()) != '\n')
            ;
         iteration_count = 0;
      } else {
         printf("%10d%10d\n", i, i * i);
      }
      
   }
   return 0;
}