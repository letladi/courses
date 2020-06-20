#include <stdio.h>

int main(void)
{
   int d, m, y;
   int min_d, min_m, min_y;
   _Bool has_date = 0, new_date_comes_first;

   do {
      printf("Enter a date (mm/dd/yy): ");
      scanf("%d / %d / %d", &m, &d, &y);
      if (d == 0 && m == 0 && y == 0) break;

      if (has_date) {
         if (y < min_y) {
            new_date_comes_first = 1;
         } else if (y > min_y) {
            new_date_comes_first = 0;
         } else if (m < min_m) {
            new_date_comes_first = 1;
         } else if (m > min_m) {
            new_date_comes_first = 0;
         } else {
            new_date_comes_first = d < min_d;
         }
         if (new_date_comes_first) {
            min_y = y;
            min_m = m;
            min_d = d;
         }
      } else {
         has_date = 1;
         min_d = d;
         min_m = m;
         min_y = y;
      }
   } while (1);   

   if (has_date) {
      printf("%d/%d/%.2d is the earliest date\n", min_m, min_d, min_y);
   } else {
      printf("\n");
   }

   return 0;
}