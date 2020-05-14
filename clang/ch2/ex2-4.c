#include <stdbool.h>
#include <stdio.h>
// #include "util.h"

void squeeze(char s1[], char s2[])
{
   int i,j, is2;
   for (int is1 = 0; s1[is1] != '\0'; is1++) {
      bool found = false;
      is2 = 0;
      int c = s1[is1];
      while (s2[is2] != '\0' && !found) {
         found = (c == s2[is2++]);
      }
      if (found) {
         for (i = j = 0; s1[i] != '\0'; i++) {
           if (s1[i] != c) s1[j++] = s1[i];
         }
         s1[j] = '\0';
      }
   }
}

int main()
{
   char s1[] = "letladi";
   char s2[] = "aei";
   squeeze(s1, s2);

   printf("squeeze('letladi', 'ae') = %s\n", s1);
}
