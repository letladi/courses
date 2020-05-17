#include <stdio.h>
#include <stdbool.h>

// convert n to string
int itoa_help(int n, char s[], bool neg, char digit)
{
   int i;
   if (n) {
      i = itoa_help(n / 10, s, neg, n % 10 + '0');
   } else {
      i = 0;
      if (neg) s[i++] = '-';
   }
   s[i++] = digit;
   return i;
}

void itoa(int n, char s[])
{
   // int i, sign;
   // if ((sign = n) < 0) n = -n;
   // i = 0;
   // do {
   //    s[i++] = n % 10 + '0';
   // } while ((n /= 10) > 0);
   //
   // if (sign < 0) s[i++] = '-';
   // s[i] = '\0';
   // reverse(s);
   bool neg = n < 0;
   n = neg ? (-1 * n) : n;
   int i = itoa_help(n / 10, s, neg, n % 10 + '0');
   s[i] = '\0';
}

int main() {
   int n = -2523480;
   char s[20];
   itoa(n, s);
}
