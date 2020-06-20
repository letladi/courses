#include <stdio.h>
#define WEEK_DAY_MIN 1
#define WEEK_DAY_MAX 7

int main(void)
{
   int month_days, week_start;
   printf("Enter number of days in month: ");
   scanf("%d", &month_days);
   printf("Enter starting day of the week (1=Sun, 7=Sat): ");
   scanf("%d", &week_start);

   int day_count = WEEK_DAY_MIN;
   for (int i = WEEK_DAY_MIN; i < week_start; i++, day_count++) printf("   ");
   for (int day = WEEK_DAY_MIN; day <= month_days; day++, day_count++) {
      if (day_count % WEEK_DAY_MAX == 0) {
         printf("%2d\n", day);
      } else {
         printf("%2d ", day);
      }
   }
   printf("\n");

   return 0;
}