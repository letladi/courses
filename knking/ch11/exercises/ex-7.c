#include <stdbool.h>
#include <stdio.h>

#define JAN 0
#define FEB 1
#define MAX_DAYS_IN_MONTH 31
#define MONTHS_IN_YR 12
#define LEAP_YEAR_FEB_DAYS 29
const int month_days[] = {
   31, 28, 31, 30, 31, 30,
   31, 31, 30, 31, 30, 31
};

// https://docs.microsoft.com/en-us/office/troubleshoot/excel/determine-a-leap-year
bool is_leap(int year)
{
   if (year % 4 == 0) { // 1.
      if (year % 100 == 0) { // 2.
         return year % 400 == 0; // 3.
      } else {
         return true; // 4.
      }
   } else {
      return false; // 5.
   }
}

void split_date(int day_of_year, int year, int *month, int *day)
{
   *month = 1;
   for (int i = JAN; i < MONTHS_IN_YR; i++, (*month)++) { 
      if (i == FEB && is_leap(year)) {
         if (day_of_year <= LEAP_YEAR_FEB_DAYS) break;
         day_of_year -= LEAP_YEAR_FEB_DAYS;
      } else {
         if (day_of_year <= month_days[i]) break;
         day_of_year -= month_days[i];
      }
   }
   *day = day_of_year;
 }

 int main(void)
 {
   int month, day;
   split_date(31, 2020, &month, &day);
   printf("split_date(31, 2020): m = %d, d = %d\n", month, day); // ✔️
   split_date(60, 2020, &month, &day);
   printf("split_date(60, 2020): m = %d, d = %d\n", month, day); // ✔️
   split_date(60, 2019, &month, &day);
   printf("split_date(60, 2019): m = %d, d = %d\n", month, day); // ✔️
   split_date(180, 2020, &month, &day);
   printf("split_date(180, 2020): m = %d, d = %d\n", month, day); // ✔️
   split_date(366, 2020, &month, &day);
   printf("split_date(366, 2020): m = %d, d = %d\n", month, day); // ✔️
   split_date(365, 2019, &month, &day);
   printf("split_date(365, 2019): m = %d, d = %d\n", month, day); // ✔️

   return 0; 
 }