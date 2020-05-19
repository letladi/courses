#include <stdio.h>
#include <stdbool.h>

bool strend(char *s, char *t)
{
   char *start_t = t;
   char *start_s = s;
   while (*t++) {
      s++;
      if (*s == '\0') {
         // s is smaller than and so can't contain t
         return false;
      }
   }

   while (*s++);

   while (t != start_t && s != start_s && (*t-- == *s--));

   return start_t == t && *t == *s;
}
