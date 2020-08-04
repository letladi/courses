#include <stdio.h>

#define NUM_MONTHS 12
const char *months[NUM_MONTHS] = { 
   "January", "February", "March", "April", "May", "June", 
   "July", "August", "September", "October", "November", "December"
};

int main(void)
{
   printf("Enter a date (mm/dd/yyyy): ");
   int d, m, y;
   scanf(" %2d/ %2d/ %4d", &m, &d, &y);

   printf("You entered the date %s %d, %d\n", months[m - 1], d, y);

   return 0;
}