#include <stdio.h>

#define MIN_PER_HR 60
#define SEC_PER_MIN 60
#define HR_PER_DAY 24
#define SEC_PER_HR (SEC_PER_MIN * MIN_PER_HR)
#define SEC_PER_DAY (SEC_PER_HR * HR_PER_DAY)

void split_double(long double num, int *int_part, long double* frac_part)
{
   *int_part = (int) num;
   *frac_part = num - *int_part;
}

void split_time(long total_sec, int *hr, int *min, int *sec)
{
   long double frac;
   split_double(total_sec / (long double)SEC_PER_HR, hr, &frac);
   *hr %= HR_PER_DAY;
   split_double(frac * MIN_PER_HR, min, &frac);
   *sec = frac * SEC_PER_MIN;
}

// Some of the second values are off by one
// rounding up the seconds causes the error of the seconds to be more than 1 (more than 10 in certain instances)
// Does that mean we should round up?

// what if the 'min' turns out to be 60, then hr should be incremented, and if the hr is 24, it should be reset
// again to 00

int main(void)
{
   int hr, min, sec;
   split_time(0, &hr, &min, &sec);
   printf("split_time(mid-night: 0) = %.2d:%.2d:%.2d\n", hr, min, sec); // ✔️
   split_time(31560, &hr, &min, &sec);
   printf("split_time(8_46: 31560) = %.2d:%.2d:%.2d\n", hr, min, sec); // displays 08:45:59
   split_time(38036, &hr, &min, &sec);
   printf("split_time(10_33_56: 38036) = %.2d:%.2d:%.2d\n", hr, min, sec); // displays 10:33:55
   split_time(43140, &hr, &min, &sec);
   printf("split_time(11_59: 43140) = %.2d:%.2d:%.2d\n", hr, min, sec); // ✔️
   split_time(300, &hr, &min, &sec);
   printf("split_time(00_05: 300) = %.2d:%.2d:%.2d\n", hr, min, sec); // ✔️
   split_time(43240, &hr, &min, &sec);
   printf("split_time(12_40: 43240) = %.2d:%.2d:%.2d\n", hr, min, sec); // ✔️
   split_time(43199, &hr, &min, &sec);
   printf("split_time(11_59_59: 43199) = %.2d:%.2d:%.2d\n", hr, min, sec); // displays 11:59:59

   return 0;
}