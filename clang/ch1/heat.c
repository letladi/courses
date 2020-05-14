#include <stdio.h>

#define STEP 20
#define LOWER 0
#define UPPER 300

float toCelcius(float);

int main()
{

   printf("Fahrenheit Celcius\n");
   for (float fahr = UPPER; fahr >= LOWER; fahr -= STEP) {
      printf("%-10.0f %-6.1f\n", fahr, toCelcius(fahr));
   }
}

float toCelcius(float fahr)
{
   return 5.0 * (fahr - 32.0) / 9.0;
}
