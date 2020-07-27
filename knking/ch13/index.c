#include <stdio.h>
#include <string.h>

int read_line(char str[], int n)
{
   int ch, i = 0;

   while ((ch = getchar()) != '\n' && ch != EOF) {
      if (i < n) str[i++] = ch;
   }
   str[i] = '\0';
   return i;
}

int count_spaces(const char *s)
{
   int count = 0;

   for ( ; *s != '\0'; s++) {
      if (*s == ' ') count++;
   }
   return count;
}

int main(void)
{
   char str1[6] = "abc";
   printf("size of str1 = %lu\n", sizeof(str1));
   strncat(str1, "def", sizeof(str1) - strlen(str1) - 1);

   return 0;
}