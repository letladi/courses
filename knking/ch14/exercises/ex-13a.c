/*
// std.io code

// space for macro line

void f(void);

int main(void)
{
   f();
   // space for macro line
   // space for macro line
   // space for macro line
   return 0;
}

void f(void)
{
   printf("N is undefined\n");
   
}
*/
#include <stdio.h>

#define N 100

void f(void);

int main(void)
{
   f();
   #ifdef N
   #undef N
   #endif
   return 0;
}

void f(void)
{
   #if defined(N)
      printf("N is %d\n", N);
   #else 
      printf("N is undefined\n");
   #endif
}