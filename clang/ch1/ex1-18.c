#include "lines.h"
#include <stdio.h>

void trim(char s[], int len);

int main()
{
   char line[] = "here is a line that requires work\n    \n But we have to start here    \t\t";
}

// returns the number of characters removed
int trim(char s[], int from, int to)
{
   // remove space/tabs
   int i = from;
   while (i <= to && s[i] != '\0') {
      s[i++] = 
   }
   return i - from + 1;
}
