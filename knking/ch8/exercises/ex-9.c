#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define DAYS_IN_MONTH 30
#define HRS_IN_DAY 24
#define MAX_TEMP 57 // https://en.wikipedia.org/wiki/Climate_of_Africa#:~:text=The%20hottest%20temperature%20recorded%20within,Libya%20on%20September%2013%2C%201922.

int main(void)
{
   double temperature_readings[DAYS_IN_MONTH][HRS_IN_DAY];
   srand((unsigned) time(NULL));
   double avg, total, val;

   for (int i = 0; i < DAYS_IN_MONTH; i++) {
      for (int j = 0; j < HRS_IN_DAY; j++) {
         total += val = rand() % MAX_TEMP;
         temperature_readings[i][j] = val;
      }
   }

   avg = total / (DAYS_IN_MONTH * HRS_IN_DAY);
   printf("avg = %f\n", avg);

   return 0;
}