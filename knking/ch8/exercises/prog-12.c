#include <stdio.h>
#include <ctype.h>
#define ALPHABET_COUNT 26

int main(void)
{
   char c;
   int sum = 0;
   int letter_value[ALPHABET_COUNT];
   printf("Enter a word: ");
   for (int i = 0, len = (int) sizeof(letter_value) / sizeof(letter_value[0]); i < len; i++) {
      c = toupper('A' + i);
      switch (c) {
         case 'A': case 'E': case 'I': case 'L': case 'N': 
         case 'O': case 'R': case 'S': case 'T': case 'U': 
            letter_value[i] = 1; break;
         case 'D': case 'G': 
            letter_value[i] = 2; break;
         case 'B': case 'C': case 'M': case 'P': 
            letter_value[i] = 3; break;
         case 'F': case 'H': case 'V': case 'W': case 'Y': 
            letter_value[i] = 4; break;
         case 'K':
            letter_value[i] = 5; break;
         case 'J': case 'X':
            letter_value[i] = 8; break;
         case 'Q': case 'Z': 
            letter_value[i] = 10; break;
            sum += 10; break;
      }
   }
   while ((c = getchar()) != '\n') {
      c = toupper(c);
      sum += letter_value[c - 'A'];
   }

   printf("Scrabble value: %d\n", sum);

   return 0;
}