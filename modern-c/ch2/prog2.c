#include <stdio.h>
#define PI 3.14159265358979323846

int main(void)
{
  float r;
  printf("Please a radius value: ");
  scanf("%f", &r);
  float volume = (4/3.0) * (PI * (r * r * r));
  printf("volume = %f\n", volume);

  return 0;
}
