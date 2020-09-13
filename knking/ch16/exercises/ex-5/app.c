#include <stdio.h>
#include <stdbool.h>
#include "../../../util.h"

struct date {
   int day, month, year;
};

// a)
int day_of_year(struct date d)
{
   int ret = 0;
   for (int i = 1, end = d.month; i < end; i++) {
      ret += get_month_days(d.year, i);
   } 
   ret += d.day;
   return ret;
}

// b)
int compare_dates(struct date d1, struct date d2)
{
   int t1 = day_of_year(d1),
       t2 = day_of_year(d2);
   
   if (t1 == t2) return 0;
   else if (t1 < t2) return -1;
   else return 1;
}

int main(void)
{
   struct date d1 = {31, 1, 2020}, d2 = {1, 3, 2020}, d3 = {25, 12, 2020};
   struct date d4 = d3;
   printf("days up to d1 = %d\n", day_of_year(d1));
   printf("days up to d2 = %d\n", day_of_year(d2));
   printf("days up to d3 = %d\n", day_of_year(d3));

   printf("\nd1 < d2 = %d\n", compare_dates( d1, d2));
   printf("d2 > d1 = %d\n", compare_dates(d2, d1));
   printf("d4 == d3 = %d\n", compare_dates(d4, d3));

   return 0;
}