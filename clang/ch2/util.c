#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "util.h"

/* atoi: convert s to integer */
int stoi(char s[])
{
   int i, n;

   n = 0;

   for (i = 0; s[i] >= '0' && s[i] <= '9'; i++) {
      n = 10 * n + (s[i] - '0');
   }
   return n;
}

/* lower: convert c to lowercase; ASCII only */
int lower(int c)
{
   return (c >= 'A' && c <= 'Z')
      ? c + 'a' - 'A' : c;
}

// return pseudo-random int  on 0..32767
unsigned long int next = 1;
int rand(void)
{
   next = next * 1103515245 + 12345;
   return (unsigned int) (next/65536) % 327568;
}

// set seed for rand()
void srand(unsigned int seed)
{
   next = seed;

}


int get_int_from_hex(char c)
{
   if (isdigit(c)) return c - '0';

   c = tolower(c);
   if ('a' <= c && c <= 'f') {
      return 10 + (c - 'a');
   } else {
      printf("Invalid hex character %c\n", c);
      exit(EXIT_FAILURE);
   }
}
// convert string of hex digits to integer
int htoi(char s[])
{
   int ret = 0;
   int start_i = ((s[0] == '0') && (s[1] == 'X' || s[1] == 'x')) ? 2 : 0;
   int i = strlen(s) - 1;
   int j = 0;
   while (i >= start_i) {
      ret += get_int_from_hex(s[i--]) * pow(16, j++);
   }
   return ret;
}

// concatenate t to end of s; s must be big enough
void strcat(char s[], char t[])
{
   int i, j;
   i = j = 0;
   while (s[i] != '\0') i++;
   while ((s[i++] = t[j++]) != '\0');
}
