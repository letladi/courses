#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>

void expand(char s1[], char s2[])
{
   int c1 = '\0',
      c2 = '\0',
      prevC = '\0',
      i1 = 0,
      i2 = 0;
   while ((c2 = s1[i1++]) != '\0') {
      // if we are 2 c's into the string and the current c is a character/digit
      // check if the previous c is a dash and the one before that is another c,
      // that is smaller than the current one
      // if so then expand
      if (prevC == '-' && (i1 > 1)) {
         bool expandable = isalnum(c1) && isalnum(c2);
         bool both_digits = isdigit(c1) && isdigit(c2);
         bool in_order = c1 < c2;
         bool same_caps = (islower(c1) && islower(c2)) || (isupper(c1) && isupper(c2));
         if (expandable && in_order && (both_digits || same_caps)) {
            i2 = i2 - 2;
            int c = c1;
            while (c <= c2) {
               s2[i2++] = c++;
            }
         } else {
            s2[i2++] = c2;
         }
      } else {
         s2[i2++] = c2;
      }
      c1 = prevC;
      prevC = c2;
   }
   s2[i2] = '\0';
}

int main()
{
   char s1[] = "k-p";
   char s2[30];
   expand(s1, s2);
   printf("expand('k-p', s2) = %s\n", s2);
}
