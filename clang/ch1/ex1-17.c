#include <stdio.h>
#include "lines.h"

int main()
{
   int len; // current line length;
   int max; // maximum length seen so far
   char line[MAXLINE]; // current input line
   char longest[MAXLINE]; // longest line saved here

   max = 0;

   while ((len = getLine(line, MAXLINE)) > 0) {
      if (len > MAXLINE) printf("\nLine is too long. Try again\n");
      else if (len > max) {
         max = len;
         copy(longest, line);
      }
   }

   if (max > 0) // there was a line
      printf("%s", longest);

   return 0;
}
