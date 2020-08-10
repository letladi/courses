#include <stdio.h>

#define ERROR(fmt, str) fprintf(stderr, fmt, str)


int main(void)
{
   int index = 22;
   fprintf(stderr, "Range error: index = %d\n", index);
   ERROR("Range error: index = %d\n", index);

   return 0;
}