#include <stdio.h>

int main(void)
{
   float wind_speed;

   printf("Enter the wind speed in knots: ");
   scanf("%f", &wind_speed);

   printf("Current situation: ");
   if (wind_speed < 1) printf("Calm");
   else if (1 <= wind_speed && wind_speed <= 3) printf("Light air");
   else if (4 <= wind_speed && wind_speed <= 27) printf("Breeze");
   else if (28 <= wind_speed && wind_speed <= 47) printf("Gale");
   else if (48 <= wind_speed && wind_speed <= 63) printf("Storm");
   else printf("Hurricane");

   printf("\n");

   return 0;
}