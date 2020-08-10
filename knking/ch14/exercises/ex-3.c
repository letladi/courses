/**
 * a) 4 ✔️
 * b) 4 ✔️
 * c) #define DOUBLE(x) (2 *(x))
*/ 

#include <stdio.h>

#define DOUBLE(x) 2*x

int main(void)
{
   printf("a) DOUBLE(1+2) = %d\n", DOUBLE(1+2));
   printf("b) 4/DOUBLE(2) = %d\n", 4/DOUBLE(2));

   return 0;
}