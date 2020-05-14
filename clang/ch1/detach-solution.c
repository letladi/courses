#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lines.h"

#define MAX_BUFFER 1024
#define SPACE ' '
#define TAB '\t'

int CalculateNumberOfSpaces(int Offset, int TabSize)
{
   return TabSize - (Offset % TabSize);
}

int main(void)
{
   char Buffer[MAX_BUFFER];
   int TabSize = 5;

   int i, j, k, l;

   while (getLine(Buffer, MAX_BUFFER) > 0) {
      for (i = 0, l = 0; Buffer[i] != '\0'; i++) {
         if (Buffer[i] == TAB) {
            printf("\n l = %d\n", l);
            j = CalculateNumberOfSpaces(l, TabSize);
            for (k = 0; k < j; k++) {
               putchar(SPACE);
               l++;
            }
         } else {
            putchar(Buffer[i]);
            l++;
         }
      }
   }

   return 0;
}
