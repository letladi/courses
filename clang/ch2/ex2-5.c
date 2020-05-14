#include <stdbool.h>
#include <stdio.h>

int any(char s1[], char s2[])
{
   int ret = -1;
   for (int j = 0; s2[j] != '\0'; j++) {
      int c = s2[j];
      for (int i = 0; s1[i] != '\0'; i++) {
         if (c == s1[i]) return i;
      }
   }
   return ret;
}
