#include <stdio.h>

int main(void)
{
   int i = 0;
   program: printf("i = %d\n", i++);
   if (i == 1) goto program;
   return 0;
}