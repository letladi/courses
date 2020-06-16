#include <stdio.h>

int main(void)
{
   int a = 5, b;
   int c = (b = a + 2) - (a = 1);

   return 0;
}