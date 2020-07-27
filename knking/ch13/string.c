#include <stddef.h>

size_t strlen(const char *s)
{
   const char *p = s;
   while (*s) s++; 
   return s - p;
}

char *strcat(char *s1, const char *s2)
{
   char *p = s1;

   while (*p) p++;
   while (*p++ = *s2++) 
      ;
   return s1;
}