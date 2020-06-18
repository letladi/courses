#include <stdio.h>

int main(void)
{
   int d1, m1, y1;
   int d2, m2, y2;

   printf("Enter first date (mm/dd/yy): ");
   scanf("%d / %d / %d", &m1, &d1, &y1);
   printf("Enter second date (mm/dd/yy): ");
   scanf("%d / %d / %d", &m2, &d2, &y2);

   _Bool first_date_comes_first;

   if (y1 < y2) {
      first_date_comes_first = 1;
   } else if (y1 > y2) {
      first_date_comes_first = 0;
   } else if (m1 < m2) {
      first_date_comes_first = 1;
   } else if (m1 > m2) {
      first_date_comes_first = 0;
   } else {
      first_date_comes_first = d1 < d2;
   }

   if (first_date_comes_first) {
      printf("%d/%d/%.2d is earlier than %d/%d/%.2d", m1, d1, y1, m2, d2, y2);
   } else {
      printf("%d/%d/%.2d is earlier than %d/%d/%.2d", m2, d2, y2, m1, d1, y1);
   }
   printf("\n");

   return 0;
}