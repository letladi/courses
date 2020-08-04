#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define MAX_WORDS 30
#define MAX_WORD_LEN 20
#define PERIOD '.'
#define EX_MARK '!'
#define Q_MARK '?'

int main(void)
{
   char terminator_c, c;
   printf("Enter a sentence: ");
   char words[MAX_WORDS][MAX_WORD_LEN] = {};
   int word_i = 0, sentence_i = 0;
   bool is_terminator_c = false;
   while (sentence_i < MAX_WORDS) {
      c = getchar();
      is_terminator_c = (c == PERIOD || c == EX_MARK || c == Q_MARK);
      if (sentence_i == MAX_WORDS) {
         terminator_c = PERIOD;
         sentence_i++;
         break;
      } else if (is_terminator_c) {
         sentence_i++;
         terminator_c = c;
         break;
      } else {
         if (isspace(c) || word_i == MAX_WORD_LEN) {
            if (word_i == 0) {
               // we don't do anything because no word is stored yet
            } else {
               words[sentence_i++][word_i] = '\0';
               word_i = 0;
            }
         } else {
            words[sentence_i][word_i++] = c;
         }
      }
   }

   printf("Reversal of sentence: ");
   while (sentence_i) {
      printf("%s", words[--sentence_i]);
      if (sentence_i) printf(" ");
   }
   printf("%c\n", terminator_c);

   return 0;
}