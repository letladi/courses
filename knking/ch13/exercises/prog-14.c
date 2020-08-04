#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define ALPHABET_COUNT 26
#define MAX_WORDS_TO_COMPARE 2
#define WORD_LEN_MAX 45 // https://en.wikipedia.org/wiki/Longest_word_in_English#:~:text=The%20longest%20word%20in%20any,is%20the%20same%20as%20silicosis.

bool are_anagrams(const char *word1, const char *word2);

int main(void)
{
   char words[MAX_WORDS_TO_COMPARE][WORD_LEN_MAX] = {0}, c;
   
   printf("Enter first word: ");
   int word = 0, len = 0;
   while ((c = getchar()) != '\n' && len < WORD_LEN_MAX) {
      words[word][len++] = c;
   }

   word++;
   len = 0;
   
   printf("Enter second word: ");
   while ((c = getchar()) != '\n' && len < WORD_LEN_MAX) {
      words[word][len++] = c;
   }

   if (are_anagrams(words[0], words[1])) {
      printf("The words are anagrams.\n");
   } else {
      printf("The words are not anagrams.\n");
   }

   return 0;
}


bool are_anagrams(const char *word1, const char *word2)
{
   int letters[ALPHABET_COUNT] = {0}, diff;
   bool is_letter;
   char c;
   while (*word1) {
      c = tolower(*word1++);
      diff = c - 'a';
      is_letter = 0 <= diff && diff < ALPHABET_COUNT;
      if (is_letter) letters[diff]++;
   }
   while (*word2) {
      c = tolower(*word2++);
      diff = c - 'a';
      is_letter = 0 <= diff && diff < ALPHABET_COUNT;
      if (is_letter) {
         letters[diff]--;
         if (letters[diff] < 0) return false;
      } 
   }
   return true;
}