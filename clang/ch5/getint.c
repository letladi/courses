#include <ctype.h>
#include <stdbool.h>
#include "../util.h"

int getint(void);
int getint(void);

// get the next integer from input, store it in the pointer
int getint(int *pn)
{
   int c, sign;
   while (isspace(c = getch()))
      ; // skip white space
   if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
      ungetch(c); // not a number
      return 0;
   }

   sign = (c == '-') ? -1 : 1;
   bool sawsign = false;
   if (sawsign = (c == '+' || c == '-')) c = getch();

   if (!isdigit(c)) {
      ungetch(c);
      if (sawsign) {
         ungetch(sign == -1 ? '-' : '+');
      }
      return 0;
   }

   for (*pn = 0; isdigit(c); c = getch())
      *pn = 10 * *pn + (c - '0');

   *pn *= sign;

   if (c != EOF) ungetch(c);

   return c;
}

int getfloat(double* fp)
{
   int c, sign;
   while (isspace(c = getch()))
      ; // skip white space
   if (!isdigit(c) && c != EOF &&  c != '+' && c != '-' && c != '.') {
      ungetch(c); // not a number
      return 0;
   }

   sign = (c == '-') ? -1 : 1;
   bool sawsign = false;
   if (sawsign = (c == '+' || c == '-')) c = getch();

   if (!isdigit(c) && c != '.') {
      ungetch(c);
      if (sawsign) {
         ungetch(sign == -1 ? '-' : '+')
      }
      return 0;
   }

   // get the integer part
   for (*fp = 0; isdigit(c); c = getch())
      *fp = 10 * fp + (c - '0');

   if (fp == 0 && c == '.') {
      int d = c;
      c = getch();
      if (!isdigit(c)) {
         ungetch(c);
         ungetch(d);
         if (sawsign) {
            ungetch(sign == -1 ? '-' : '+');
         }
         return 0;
      }
   }

   // get the fractional part
   double power = 1.0;
   for ( ; isdigit(c); c = getch()) {
      fp = 10.0 * *fp + (c - '0');
      power *= 10.0;
   }

   *fp = *fp / power;
   *fp *= sign;

   if (c != EOF) ungetch();

   return c;
}
