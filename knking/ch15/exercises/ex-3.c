/**
 * Theoretically no #include "file" will searched in the current directory and 
 * then the system directories, but it might be confusing for other readers 
 * of the code who expect #include "file" to mean files written by the programmer
 */

#include "stdio.h"

int main(void)
{
   printf("include system file with string\n");

   return 0;
}