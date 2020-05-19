#include <stdio.h>

void strcat(char* s, char* t)
{
   while (*s++);
   s--;
   while ((*s++ = *t++));
}

int main()
{
   char s[20] = "letladi";
   char t[20] = " sebesho";
   strcat(s, t);
   printf("\ns = %s\n", s);
}
