#include <stdio.h>
#include <stdbool.h>
#define MAX_LEN 1000

int main(void)
{
   char sentence[MAX_LEN] = {0}, terminator_c, c;
   printf("Enter a sentence: ");
   int len = 0;
   bool is_terminator_c = false;
   while (len < MAX_LEN) {
      c = getchar();
      is_terminator_c = (c == '.' || c == '!' || c == '\?');
      if (is_terminator_c) {
         printf("we have a terminator, %c\n", c);
         terminator_c = c;
         break;
      }
      else sentence[len++] = c;
   }

   printf("Reversal of sentence: ");
   int i = len - 1, j, new_end;
   while (i >= 0) {
      j = i;
      while (sentence[j] != ' ' && j > 0) {
         j--;
      }
      new_end = j - 1;

      
      if (j > 0) j++;
      while (j <= i) {
         printf("%c", sentence[j++]);
      }

      
      i--;
      i = new_end;
      if (i > 0) printf(" ");
   }
   printf("%c\n", terminator_c);

   return 0;
}