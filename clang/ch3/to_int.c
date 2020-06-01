#include <ctype.h>
#include <stdio.h>

int to_int(char s[])
{
   int i, n, sign;
   for (i = 0; isspace(s[i]); i++) /* skip white space */;
   int is_minus = s[i] == '-';
   
   sign = (is_minus) ? -1 : 1;
   if (s[i] == '+' || is_minus) i++;
   for (n = 0; isdigit(s[i]); i++)
      n = 10 * n + (s[i] - '0');

   return sign * n;
}