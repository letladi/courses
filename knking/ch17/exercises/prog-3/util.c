#include <stdio.h>
#include "util.h"

int read_line(char str[], int n)
{
   int ch, i = 0;
   int count = 0;
   while ((ch = getchar())) {
      if (ch == '\n') {
         if (i == 0) { // this might be a new line left over from a previous read, either way, we skip it
            if (count) { // second new line indicates user is done with entry
               break;
            } else {
               count++;
               continue; 
            }
         } else {
            break;
         }
      }
      str[i++] = ch;
      
   }
   
   str[i] = '\0';
   return i;
}
