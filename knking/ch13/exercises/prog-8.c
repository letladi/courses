#include <stdio.h>
#include <ctype.h>

#define WORD_LEN 50

int compute_scrabble_value(const char *word)
{
   int sum = 0;
   while (*word) {
      switch (toupper(*word)) {
         case 'A': case 'E': case 'I': case 'L': case 'N': 
         case 'O': case 'R': case 'S': case 'T': case 'U': 
            sum += 1; break;
         case 'D': case 'G': 
            sum += 2; break;
         case 'B': case 'C': case 'M': case 'P': 
            sum += 3; break;
         case 'F': case 'H': case 'V': case 'W': case 'Y': 
            sum += 4; break;
         case 'K':
            sum += 5; break;
         case 'J': case 'X':
            sum += 8; break;
         case 'Q': case 'Z': 
            sum += 10; break;
      }
      word++;
   }
   return sum;
}

int main(void)
{
   char c, word[WORD_LEN];
   int sum = 0, i = 0;

   printf("Enter a word: ");
   while ((c = getchar()) != '\n') {
      word[i++] = c;
   }
   word[i] = '\0';

   printf("Scrabble value: %d\n", compute_scrabble_value(word));

   return 0;
}