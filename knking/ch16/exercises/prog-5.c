#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MAX_TIME_DIFF_DEFAULT 24.0f * 60.0f
#define NUM_DEPART_TIMES 8
#define SECONDS_IN_MIN 60
#define MIN_IN_HR 60
#define TWELF_PM 12*MIN_IN_HR

int hr(long total_minutes)
{
   return total_minutes / MIN_IN_HR;
}

int min(long total_minutes)
{
   return total_minutes - (hr(total_minutes) * 60);
}

bool is_am(long total_minutes)
{
   return total_minutes < TWELF_PM;
}

struct time {
   long departure_time, arrival_time;
};

int main(void)
{
   int hour, minutes;
   printf("Enter a 24-hour time: ");
   scanf("%d : %d", &hour, &minutes);

   struct time times[NUM_DEPART_TIMES] = {
      {8*60+0, 10*60+16}, // 8:00am,10:16am
      {9*60+43, 11*60+52}, // 9:43am, 11:52am
      {11*60+19, 13*60+31}, // 11:19am, 13:31pm
      {12*60+47, 15*60+0}, // 12:47pm, 15:00pm
      {14*60+0, 16*60+8}, // 14:00pm, 16:08pm
      {15*60+45, 17*60+5}, // 15:45pm, 17:55pm
      {19*60+0, 21*60+20}, // 19:00pm, 21:20pm
      {21*60+45, 23*60+58}, // 21:45pm, 23:58pm
   };

   float current_time_val = hour * 60 + minutes;

   long current_time_diff_min = MAX_TIME_DIFF_DEFAULT, test_diff;
   struct time closest_time;

   for (int i = 0; i < NUM_DEPART_TIMES; i++) {
      test_diff = fabsf(times[i].departure_time - current_time_val);
      if (test_diff < current_time_diff_min) {
         current_time_diff_min = test_diff;
         closest_time = times[i];
      }
   }

   printf("Closest departure time %d:%.2d ", hr(closest_time.departure_time), min(closest_time.departure_time));
   printf(is_am(closest_time.departure_time) ? "a.m" : "p.m");
   printf(", arriving at %d:%.2d ", hr(closest_time.arrival_time), min(closest_time.arrival_time));
   printf(is_am(closest_time.arrival_time) ? "a.m." : "p.m.");
   printf("\n");

   return 0;
}