#include <stdbool.h>
#include <string.h>

void strncpy(char *d, char *s, int n)
{
   int i = 0;
   while (*d++ = *s++) {
      if (i == n) {
         *d = '\0';
         break;
      }
      i++;
   }
}

void strncat(char *d, char *s, int n)
{
   int i = strlen(d);
   while (d[i++] = *s++) {
      if (i == n) {
         *d = '\0';
         break;
      }
   }
}

void strncmp(char *d, char *s, int n)
{
   int i = 0;
   while (*d++ == *s++) {
      if (i == n) return true;
   }
   return false;
}
