#include <ctype.h>
#include <stdio.h>
#include "getch.h"

#define BUFSIZE 100

char buf[BUFSIZE]; // buffer for ungetch
int bufp = 0; // next free position in buf

int getch(void) // get a (possibly pushed back) character
{
   return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) // push character back on input
{
   // we don't push back an EOF
   if (c == EOF) return;
   if (bufp >= BUFSIZE) printf("ungetch: too many characters\n");
   else buf[bufp++] = c;
}

void ungets(char s[])
{
   int i = 0;
   while (s[i]) ungetch(s[i++]);
}
