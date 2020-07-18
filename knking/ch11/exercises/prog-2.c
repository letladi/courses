#include <stdio.h>
#include <stdbool.h>

#define MAX_TIME_DIFF_DEFAULT 24.0f * 60.0f

/**** FROM exercise 5 of ch11 ****/
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
/**** end of snippet ****/

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time)
{
   int hr, min, sec;
   split_time(desired_time * SEC_PER_MIN, &hr, &min, &sec);

   float t1 = 8 * 60 + 0; // 8:00am
   float t2 = 9 * 60 + 43; // 9:43am
   float t3 = 11 * 60 + 19; // 11:19am
   float t4 = 12 * 60 + 47; // 12:47pm
   float t5 = 14 * 60 + 0; // 2:00pm
   float t6 = 15 * 60 + 45; // 3:45pm
   float t7 = 19 * 60 + 0; // 7:00pm
   float t8 = 21 * 60 + 45; // 9:45pm

   bool is_am = hr < 12;
   float current_time_diff_min = MAX_TIME_DIFF_DEFAULT, test_diff;
   int closest_hr, closest_min, arriving_hr, arriving_min;
   bool departing_in_am, arriving_in_am;

   test_diff = t1 - desired_time;
   test_diff = test_diff > 0 ? test_diff : -1 * test_diff;
   if (test_diff < current_time_diff_min) {
      current_time_diff_min = test_diff;
      closest_hr = 8; closest_min = 0; arriving_hr = 10; arriving_min = 16;
         departing_in_am = true;
         arriving_in_am = true;
   }

   test_diff = t2 - desired_time;
   test_diff = test_diff > 0 ? test_diff : -1 * test_diff;
   if (test_diff < current_time_diff_min) {
      current_time_diff_min = test_diff;
      closest_hr = 9; closest_min = 43; arriving_hr = 11; arriving_min = 52;
         departing_in_am = true;
         arriving_in_am = true;
   }

   test_diff = t3 - desired_time;
   test_diff = test_diff > 0 ? test_diff : -1 * test_diff;
   if (test_diff < current_time_diff_min) {
      current_time_diff_min = test_diff;
      closest_hr = 11; closest_min = 19; arriving_hr = 13; arriving_min = 31;
      departing_in_am = true;
      arriving_in_am = false;
   }

   test_diff = desired_time - t4;
   test_diff = test_diff > 0 ? test_diff : -1 * test_diff;
   if (test_diff < current_time_diff_min) {
      current_time_diff_min = test_diff;
      closest_hr = 12; closest_min = 47; arriving_hr = 15; arriving_min = 0;
      departing_in_am = false;
      arriving_in_am = false;
   }

   test_diff = desired_time - t5;
   test_diff = test_diff > 0 ? test_diff : -1 * test_diff;
   if (test_diff < current_time_diff_min) {
      current_time_diff_min = test_diff;
      closest_hr = 14; closest_min = 0; arriving_hr = 16; arriving_min = 8;
      departing_in_am = false;
      arriving_in_am = false;
   }

   test_diff = desired_time - t6;
   test_diff = test_diff > 0 ? test_diff : -1 * test_diff;
   if (test_diff < current_time_diff_min) {
      current_time_diff_min = test_diff;
      closest_hr = 15; closest_min = 45; arriving_hr = 17; arriving_min = 5;
      departing_in_am = false;
      arriving_in_am = false;
   }

   test_diff = desired_time - t7;
   test_diff = test_diff > 0 ? test_diff : -1 * test_diff;
   if (test_diff < current_time_diff_min) {
      current_time_diff_min = test_diff;
      closest_hr = 19; closest_min = 0; arriving_hr = 21; arriving_min = 20;
      departing_in_am = false;
      arriving_in_am = false;
   }

   // some a.m times might be closer to 9:45 than 8:00 so we make provision for that
   if (is_am) t8 -= 24 * 60;

   test_diff = desired_time - t8;
   test_diff = test_diff > 0 ? test_diff : -1 * test_diff;
   if (test_diff < current_time_diff_min) {
      current_time_diff_min = test_diff;
      closest_hr = 21; closest_min = 45; arriving_hr = 23; arriving_min = 58;
      departing_in_am = false;
      arriving_in_am = false;
   }

   // if (!departing_in_am) closest_hr += 12;
   // if (!arriving_in_am) arriving_hr += 12;

   *departure_time = closest_hr * MIN_PER_HR + closest_min;
   *arrival_time = arriving_hr * MIN_PER_HR + arriving_min;
}

bool is_am(int hr)
{
   return hr < 12;
}

int main(void)
{
   int hr, min;
   printf("Enter a 24-hour time: ");
   scanf("%d : %d", &hr, &min);

   float current_time_val = hr * 60 + min;
   int minutes_arrival_time, 
       minutes_departure_time, 
       closest_hr, 
       closest_min, 
       arriving_hr, 
       arriving_min, 
       unused_sec;
   
   find_closest_flight(current_time_val, &minutes_departure_time, &minutes_arrival_time);
   split_time(minutes_departure_time * SEC_PER_MIN, &closest_hr, &closest_min, &unused_sec);
   split_time(minutes_arrival_time * SEC_PER_MIN, &arriving_hr, &arriving_min, &unused_sec);

   bool departing_in_am = is_am(closest_hr);
   if (closest_hr == 0) closest_hr = 12;
   if (arriving_hr == 0) arriving_hr = 12;
   if (!departing_in_am && closest_hr != 12) closest_hr -= 12;
   bool arriving_in_am = is_am(arriving_hr);
   if (!arriving_in_am && arriving_hr != 12) arriving_hr -= 12;

   printf("Closest departure time %d:%.2d ", closest_hr, closest_min);
   printf(departing_in_am ? "a.m" : "p.m");
   printf(", arriving at %d:%.2d ", arriving_hr, arriving_min);
   printf(arriving_in_am ? "a.m." : "p.m.");
   printf("\n");

   return 0;
}