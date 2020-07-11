#include <stdio.h>
#include <stdbool.h>

#define LEAP_FEB_DAYS 29
#define FEB_DAYS 28
#define MONTH_CNT 12
#define FEB_MONTH 1
#define JAN_MONTH 0



// https://docs.microsoft.com/en-us/office/troubleshoot/excel/determine-a-leap-year
bool is_leap(int yr)
{  
   if (yr % 4 == 0) {
      if (yr % 100 == 0) {
         return yr % 400;
      } else {
         return true;
      }
   } 
   return false;
}  

const int month_days[MONTH_CNT] = {
   31, 28, 31, 30, 31, 30, 
   31, 31, 30, 31, 30, 31
};

int day_of_year(int month, int day, int year)
{
   int ret = 0;
   for (int i = JAN_MONTH; i < month - 1; i++) {
      if (FEB_MONTH == i) {
         ret += is_leap(year) ? LEAP_FEB_DAYS : FEB_DAYS;
      } else {
         ret += month_days[i];
      }
   }
   ret += day;

   return ret;
}
// ✔️