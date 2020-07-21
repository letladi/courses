#include <stdio.h>
#include <stdbool.h>
#define MAX_LEN 1000

int main(void)
{
   char sentence[MAX_LEN] = {0}, terminator_c, c;
   printf("Enter a sentence: ");
   char *len = sentence, *end = sentence + MAX_LEN, *start = sentence;
   bool is_terminator_c = false;
   while (len < end) {
      c = getchar();
      is_terminator_c = (c == '.' || c == '!' || c == '\?');
      if (is_terminator_c) {
         terminator_c = c;
         break;
      }
      else *len++ = c;
   }

   printf("Reversal of sentence: ");
   char *i = len - 1, *j, *new_end;
   while (i >= start) {
      j = i;
      while (*j != ' ' && j > start) {
         j--;
      }
      new_end = j - 1;

      
      if (j > start) j++;
      while (j <= i) {
         printf("%c", *j++);
      }

      i--;
      i = new_end;
      if (i > start) printf(" ");
   }
   printf("%c\n", terminator_c);

   return 0;
}