#include <stdio.h>

#define SECONDS_IN_HR 3600
#define SECONDS_IN_MINUTE 60

struct time {
   int hours, minutes, seconds;
};

struct time split_time(long total_seconds)
{
   int hr = total_seconds / SECONDS_IN_HR;
   total_seconds -= hr * SECONDS_IN_HR;
   int min = total_seconds / SECONDS_IN_MINUTE;
   total_seconds -= min * SECONDS_IN_MINUTE;
   int seconds = total_seconds;

   return (struct time) {.hours = hr, .minutes = min, .seconds = seconds };
}

int main(void)
{
   int five_40_25 = 20425;
   int twenty_15_55 = 72955;
   struct time t1 = split_time(five_40_25);
   struct time t2 = split_time(twenty_15_55);
   printf("hr = %d, min = %d, sec = %d\n", t1.hours, t1.minutes, t1.seconds);
   printf("hr = %d, min = %d, sec = %d\n", t2.hours, t2.minutes, t2.seconds);
   
   return 0;
}