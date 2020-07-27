#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define WORD_LEN 20
#define EXIT_LEN 4

int main(void)
{
   char smallest_word[WORD_LEN + 1] = {}, largest_word[WORD_LEN + 1] = {}, word[WORD_LEN + 1], ch;
   int len = 0;
   do {
      printf("Enter word: ");
      while (len < WORD_LEN - 1) {
         ch = getchar();
         ch = tolower(ch);
         if ('a' <= ch && ch <= 'z') word[len++] = ch;
         else if (isspace(ch) && len > 0) break;
      }
      word[len] = '\0';

     
      if (strlen(smallest_word) == 0 && strlen(largest_word) == 0) {
         strcpy(smallest_word, word);
         strcpy(largest_word, word);
      } else if (strcmp(word, smallest_word) < 0) {
         strcpy(smallest_word, word);
      } else if (strcmp(word, largest_word) > 0) {
         strcpy(largest_word, word);
      }

       if (len == EXIT_LEN) break;
       else {
          len = 0;
       }

   } while (true);

   printf("Smallest word: %s\n", smallest_word);
   printf("Largest word: %s\n", largest_word);

   return 0;
}

// ✔️