#include <stdio.h>
#include <stdbool.h>

#define MAX_TIME_DIFF_DEFAULT 24.0f * 60.0f
// td = time of depature
#define td_8_00 0 
#define td_9_43 1
#define td_11_19 2
#define td_12_47 3
#define td_14_00 4
#define td_15_45 5
#define td_19_00 6
#define td_21_45 7
// these are array indices into the arrival/departure times array of arrays
#define tHR 0
#define tMIN 1

int main(void)
{
   int hr, min;
   printf("Enter a 24-hour time: ");
   scanf("%d : %d", &hr, &min);

   float current_time_val = hr * 60 + min;
   float t1 = 8 * 60 + 0; // 8:00am
   float t2 = 9 * 60 + 43; // 9:43am
   float t3 = 11 * 60 + 19; // 11:19am
   float t4 = 12 * 60 + 47; // 12:47pm
   float t5 = 14 * 60 + 0; // 2:00pm
   float t6 = 15 * 60 + 45; // 3:45pm
   float t7 = 19 * 60 + 0; // 7:00pm
   float t8 = 21 * 60 + 45; // 9:45pm

   // departure time array
   float departures[][2] = {
      {8, 0}, // 8:00am
      {9, 43}, // 9:43am
      {11, 19}, // 11:19am
      {12, 47}, // 12:47pm
      {14, 0}, // 2:00pm
      {15, 45}, // 3:45pm
      {19, 0}, // 7:00pm
      {21, 45}// 9:45pm
   };
   float arrivals[] = {

   };

   bool is_am = hr < 12;
   float current_time_diff_min = MAX_TIME_DIFF_DEFAULT, test_diff;
   int closest_hr, closest_min, arriving_hr, arriving_min;
   bool departing_in_am;

   test_diff = t1 - current_time_val;
   test_diff = test_diff > 0 ? test_diff : -1 * test_diff;
   if (test_diff < current_time_diff_min) {
      current_time_diff_min = test_diff;
      closest_hr = 8; closest_min = 0; arriving_hr = 10; arriving_min = 16;
         departing_in_am = true;
   }

   test_diff = t2 - current_time_val;
   test_diff = test_diff > 0 ? test_diff : -1 * test_diff;
   if (test_diff < current_time_diff_min) {
      current_time_diff_min = test_diff;
      closest_hr = 9; closest_min = 43; arriving_hr = 11; arriving_min = 52;
         departing_in_am = true;
   }

   test_diff = t3 - current_time_val;
   test_diff = test_diff > 0 ? test_diff : -1 * test_diff;
   if (test_diff < current_time_diff_min) {
      current_time_diff_min = test_diff;
      closest_hr = 11; closest_min = 19; arriving_hr = 1; arriving_min = 31;
      departing_in_am = true;
   }

   test_diff = current_time_val - t4;
   test_diff = test_diff > 0 ? test_diff : -1 * test_diff;
   if (test_diff < current_time_diff_min) {
      current_time_diff_min = test_diff;
      closest_hr = 12; closest_min = 47; arriving_hr = 3; arriving_min = 0;
      departing_in_am = false;
   }

   test_diff = current_time_val - t5;
   test_diff = test_diff > 0 ? test_diff : -1 * test_diff;
   if (test_diff < current_time_diff_min) {
      current_time_diff_min = test_diff;
      closest_hr = 2; closest_min = 0; arriving_hr = 4; arriving_min = 8;
      departing_in_am = false;
   }

   test_diff = current_time_val - t6;
   test_diff = test_diff > 0 ? test_diff : -1 * test_diff;
   if (test_diff < current_time_diff_min) {
      current_time_diff_min = test_diff;
      closest_hr = 3; closest_min = 45; arriving_hr = 5; arriving_min = 5;
      departing_in_am = false;
   }

   test_diff = current_time_val - t7;
   test_diff = test_diff > 0 ? test_diff : -1 * test_diff;
   if (test_diff < current_time_diff_min) {
      current_time_diff_min = test_diff;
      closest_hr = 7; closest_min = 0; arriving_hr = 9; arriving_min = 20;
      departing_in_am = false;
   }

   // some a.m times might be closer to 9:45 than 8:00 so we make provision for that
   if (is_am) t8 -= 24 * 60;

   test_diff = current_time_val - t8;
   test_diff = test_diff > 0 ? test_diff : -1 * test_diff;
   if (test_diff < current_time_diff_min) {
      current_time_diff_min = test_diff;
      closest_hr = 9; closest_min = 45; arriving_hr = 11; arriving_min = 58;
      departing_in_am = false;
   }

   printf("Closest departure time %d:%.2d ", closest_hr, closest_min);
   printf(is_am ? "a.m" : "p.m");
   printf(", arriving at %d:%.2d ", arriving_hr, arriving_min);
   printf(departing_in_am ? "a.m." : "p.m.");
   printf("\n");

   return 0;
}