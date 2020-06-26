#include <stdio.h>
#include <math.h>
#define MARGIN 0.00001
#define GUESS 1.0

int main(void)
{
   double x, y = GUESS, old_y, avg, sqrt;
   _Bool starting = 1;
   printf("Enter a positive number: ");
   scanf(" %lf", &x);

   while (1) {
      avg = (y + x / y) / 2.0;
      
      if (starting) {
         starting = 0;
      } else {
         if (fabs(y - old_y) < (MARGIN * y)) break;
      }
      old_y = y;
      y = avg;
   }

   printf("Square root: %.5f\n", avg);

   return 0;
}