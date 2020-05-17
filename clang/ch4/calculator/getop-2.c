#include <stdio.h>
#include <ctype.h>
#include "getop.h"
#include "getch.h"
#define EMPTY '\0'
// get next operator or numeric operand
int getop(char s[])
{
   int i,
      c = '\0',
      start_i = 0;
   static int lastC;


   // while ((s[0] = c = (c || getch())) == ' ' || c == '\t')
   do {
      if (lastC) {
         c = lastC;
         lastC = EMPTY;
      } else {
         s[0] = c = getch();
      }
   } while (c == ' ' || c == '\t');

   s[1] = '\0';

   if (!isdigit(c) && c != '.' && c != '-')
      return c; // not a number

   if (c == '-') {
      int d = getch();
      if (isdigit(d) || d == '.') {
         s[2] = '\0';
         s[1] = d;
         s[0] = c;
         c = d;
         start_i = 1;
      } else {
         // ungetch(d);
         lastC = d;
         return c;
      }
   }

   i = start_i;
   if (isdigit(c))   // collect integer part
      while (isdigit(s[++i] = c = getch()))
         ;

   if (c == '.') // collect fraction part
      while (isdigit(s[++i] = c = getch()))
         ;

   s[i] = '\0';
   if (c != EOF) {
      // ungetch(c);
      lastC = c;
   }

   return NUMBER;
}
