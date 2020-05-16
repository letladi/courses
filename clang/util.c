#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include "util.h"

#define MAX_EXPONENT_LEN 4

// reverse string in place
void reverse(char s[])
{
   int c, i, j;
   for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
      c = s[i], s[i] = s[j], s[j] = c;
   }
}

// convert n to string
void itoa(int n, char s[])
{
   int i, sign;
   if ((sign = n) < 0) n = -n;
   i = 0;
   do {
      s[i++] = n % 10 + '0';
   } while ((n /= 10) > 0);

   if (sign < 0) s[i++] = '-';
   s[i] = '\0';
   reverse(s);
}

// remove trailing blanks, tabs, newlines
int trim(char s[])
{
   int n;
   for (n = strlen(s) - 1; n >= 0; n--)
      if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n') break;

   s[n+1] = '\0';
   return n;
}

int getLine(char s[], int lim)
{
   int c, i;
   i = 0;
   while (--lim > 0 && (c = getchar()) != EOF && c != '\n') s[i++] = c;
   if (c == '\n') s[i++] = c;
   s[i] = '\0';
   return i;
}

// return index of t in s, -1 if none
int strindex(char s[], char t[])
{
   int i, j, k;
   for (i = 0; s[i] != '\0'; i++) {
      for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
         // empty loop body;
         ;
      if (k > 0 && t[k] == '\0') return i;
   }
   return -1;
}

int strrindex(char s[], char t[])
{
   int i, j, k, tLen = strlen(t), sLen = strlen(s);
   for (i = sLen - tLen; i >= 0; i--) {
      for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
         // empty loop body
         ;
      if (k > 0 && t[k] == '\0') return i;
   }
   return -1;
}

// convert string to double
double stof(char s[])
{
   double val, power, exp;
   int i, sign;
   bool negExpSign;
   for (i = 0; isspace(s[i]); i++)
      // skip white space
      ;
   sign = (s[i] == '-') ? -1 : 1;
   if (s[i] == '+' || s[i] == '-') i++;

   for (val = 0.0; isdigit(s[i]); i++)
      val = 10.0 * val + (s[i] - '0');
   if (s[i] == '.')
      i++;

   for (power = 1.0; isdigit(s[i]); i++) {
      val = 10.0 * val + (s[i] - '0');
      power *= 10.0;
   }

   exp = 1.0;
   if (s[i] == 'E' || s[i] == 'e') {

      negExpSign = s[++i] == '-';
      if (s[i] == '+' || s[i] == '-') i++;
      char expChars[MAX_EXPONENT_LEN];
      int j = 0;
      while (s[i] != '\0') expChars[j++] = s[i++];
      expChars[j] = '\0';
      exp *= pow(10, (int) stof(expChars));
      exp = negExpSign ? (1.0 / exp) : exp;
   }

   return (sign * val / power) * exp;
}

// convert string s to integer using stof
int stoi(char s[])
{
   return (int) stof(s);
}
