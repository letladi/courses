#include <stdio.h>
#include "util.h"

// https://docs.microsoft.com/en-us/office/troubleshoot/excel/determine-a-leap-year
bool is_leap(int yr)
{  
   if (yr % 4 == 0) {
      if (yr % 100 == 0) {
         return yr % 400 == 0;
      } else {
         return false;
      }
   } else {
      return false;
   }
}

const int month_days[] = {
   31, 28, 31, 30, 31, 30,
   31, 31, 30, 31, 30, 31
};

int get_month_days(int yr, int month)
{
   if (month == 2) {
      return !is_leap(month) ? 29 : month_days[month - 1];
   } else {
      return month_days[month - 1];
   }
}

int gcd(int a, int b)
{
   if (b == 0) return a;
   else return gcd(b, a % b);
}

int read_line(char str[], int n)
{
   int ch, i = 0;
   while ((ch = getchar()) != '\n' && (i < n)) {
      str[i++] = ch;
   }
   str[i] = '\0';
   return i;
}
