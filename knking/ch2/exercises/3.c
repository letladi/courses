#include <stdio.h>
#define PI 3.141592653589793238f

int main()
{
   float r = 10.0f;

   printf("Please enter the radius of a circle: ");
   scanf("%f", &r);
   float v = (4.0f / 3.0f) * PI * ( r * r * r);

   printf("volume of circle (with r = %.2f) is v = %.2f\n", r, v);

   return 0;
}