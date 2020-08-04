#include <stdio.h>

int compute_vowel_count(const char *sentence)
{
   int count = 0;
   while (*sentence) {
      switch(*sentence) {
         case 'a': case 'e': case 'i': case 'o': case 'u':
         case 'A': case 'E': case 'I': case 'O': case 'U':
            count++; break;
      }
      sentence++;
   }
   return count;
}

int main(void)
{
   printf("letladi = %d\n", compute_vowel_count("zgzh"));

   return 0;
}