#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define BACKSLASH '\\'

void escape(char s[], char t[])
{
   int i = 0;
   int j = 0;
   while (t[i] != '\0') {
      int c = t[i];
      if (c == '\t') {
         strcat(s, "\\t");
         j += 2;
      } else if (c == '\n') {
         strcat(s, "\\n");
         j += 2;
      } else {
         s[j++] = c;
      }
      i++;
   }
   s[j] = '\0';
}

void reverse_escape(char s[], char t[])
{
   int j = 0;
   for (int i = 0; t[i] != '\0'; i++) {
      int c = t[i];
      printf("c = %c\n", c);
      int newC;
      bool isT = c == 't';
      if (isT || c == 'n') {
         if (i > 0 && t[i - 1] == BACKSLASH) {
            j--;
            s[j++] = isT ? '\t' : '\n';
         } else {
            s[j++] = c;
         }
      } else {
         s[j++] = c;
      }  
   }
   s[j] = '\0';
}

int main()
{
   char s[20];
   escape(s, "\tletladi\nsebesho");
   printf("%s\nlen = %lu\n", s, strlen(s));
   char t[20];
   reverse_escape(t, s);

   printf("new string = %s\n", t);
}
