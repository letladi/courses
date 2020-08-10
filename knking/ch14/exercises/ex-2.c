#include <stdio.h>

#define NELEMS(a) ((int) (sizeof((a)) / sizeof((a[0]))))

int main(void)
{
   char a[50];
   printf("nelems(a) = %d\n", NELEMS(a));
}