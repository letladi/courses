#include <stdio.h>
#include <stdbool.h>

struct date {
   int month, day, year;
};

int compare_dates(struct date d1, struct date d2)
{
   int diff = d1.year - d2.year;
   if (diff != 0) return diff;
   diff = d1.month - d2.month;
   if (diff != 0) return diff;
   else {
      return d1.day - d2.day;
   }
}

void print_date(struct date d)
{
   printf("%d/%d/%.2d", d.month, d.day, d.year);
}

int main(void)
{
   struct date d1, d2;

   printf("Enter first date (mm/dd/yy): ");
   scanf("%d / %d / %d", &d1.month, &d1.day, &d1.year);
   printf("Enter second date (mm/dd/yy): ");
   scanf("%d / %d / %d", &d2.month, &d2.day, &d2.year);

   bool first_date_comes_first = compare_dates(d1, d2) < 0;

   struct date earlier_date, later_date;
   if (first_date_comes_first) {
      earlier_date = d1; later_date = d2;
   } else {
      earlier_date = d2; later_date = d1;
   }

   print_date(earlier_date);
   printf(" is earlier than ");
   print_date(later_date);
   printf("\n");

   return 0;
}