#include <stdio.h>
#include <stdbool.h>

#define MINUTES_IN_HR 60.0f
#define MAX_TIME_DIFF_DEFAULT 24.0f * MINUTES_IN_HR
// these are array indices into the arrival/departure times array of arrays
#define tHR 0
#define tMIN 1
#define TIME_PARTS 2

int main(void)
{
   int hr, min;
   printf("Enter a 24-hour time: ");
   scanf("%d : %d", &hr, &min);

   const float current_time_val = hr * MINUTES_IN_HR + min;

   // departure time array
   float departures[][TIME_PARTS] = {
      {8, 0}, 
      {9, 43}, 
      {11, 19}, 
      {12, 47}, 
      {14, 0}, 
      {15, 45}, 
      {19, 0}, 
      {21, 45}
   };
   float arrivals[][TIME_PARTS] = {
      {10, 16},
      {11, 52},
      {13, 31},
      {15, 0},
      {16, 8},
      {17, 55},
      {21, 20},
      {23, 58}
   };

   bool is_am = hr < 12;
   float current_time_diff_min = MAX_TIME_DIFF_DEFAULT;
   int closest_hr, closest_min, arriving_hr, arriving_min;
   bool departing_in_am;

   float test_diff, dt;
   for (int i = 0, len  = (int) sizeof(departures) / sizeof(departures[0]); i < len; i++) {
      dt = departures[i][tHR] * MINUTES_IN_HR + departures[i][tMIN];
      test_diff = dt - current_time_val;
      test_diff = test_diff > 0 ? test_diff : -1 * test_diff;
      if (test_diff < current_time_diff_min) {
         current_time_diff_min = test_diff;
         closest_hr = departures[i][tHR];
         closest_min = departures[i][tMIN];
         arriving_hr = arrivals[i][tHR];
         arriving_min = arrivals[i][tMIN];
         departing_in_am = (0 <= closest_hr && closest_hr <= 11);
      }
   }

   printf("Closest departure time %d:%.2d ", closest_hr, closest_min);
   printf(is_am ? "a.m" : "p.m");
   printf(", arriving at %d:%.2d ", arriving_hr, arriving_min);
   printf(departing_in_am ? "a.m." : "p.m.");
   printf("\n");

   return 0;
}