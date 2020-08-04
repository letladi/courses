#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_PLANETS 9

int str_cmp(const char *s1, const char *s2)
{
   while (*s1 && *s2) {
      if (tolower(*s1) != tolower(*s2)) return *s1 - *s2;
      s1++; s2++;
   }

   if (*s1) return *s1;
   else if (s2) return *s2;
   else return 0;
}

int main(int argc, char *argv[])
{
   char *planets[] = { 
      "Mercury", "Venus", "Earth", "Mars", "Jupiter",
      "Saturn", "Uranus", "Neptune", "Pluto"
   };

   int i, j;

   for (i = 1; i < argc; i++) {
      for (j = 0; j < NUM_PLANETS; j++) {
         if (str_cmp(argv[i], planets[j]) == 0) {
            printf("%s is planet %d\n", argv[i], j + 1);
            break;
         }
      }
      if (j == NUM_PLANETS) {
         printf("%s is not a planet\n", argv[i]);
      }
   }

   return 0;
}