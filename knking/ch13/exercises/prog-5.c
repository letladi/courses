#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   int sum = 0;
   while (--argc) {
      sum += atoi(argv[argc]);
   }
   printf("Total: %d\n", sum);

   return 0;
}