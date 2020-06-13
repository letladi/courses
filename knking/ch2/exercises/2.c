#include <stdio.h>
#define PI 3.141592653589793238f

int main()
{
   float r = 10.0f,
         v = (4.0f / 3.0f) * PI * ( r * r * r);

   printf("v = %f\n", v);

   return 0;
}