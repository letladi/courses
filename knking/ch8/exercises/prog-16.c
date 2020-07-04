#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define ALPHABET_COUNT 26
#define WORD_LEN_MAX 45 // https://en.wikipedia.org/wiki/Longest_word_in_English#:~:text=The%20longest%20word%20in%20any,is%20the%20same%20as%20silicosis.

int main(void)
{
   char word[WORD_LEN_MAX], c;
   int letters[ALPHABET_COUNT] = {0};

   printf("Enter first word: ");
   int len1 = 0, diff;
   while ((c = getchar()) != '\n' && len1 < WORD_LEN_MAX) {
      c = tolower(c);
      diff = c - 'a';
      if (0 <= diff  && diff < ALPHABET_COUNT) {
         letters[diff]++;
      }

      len1++;
   }
   
   printf("Enter second word: ");
   int len2 = 0;
   bool is_anagram = true;
   while ((c = getchar()) != '\n' && len2 < WORD_LEN_MAX) {
      if (len2 > len1) {
         is_anagram = false;
         break;
      }

      c = tolower(c);
      diff = c - 'a';
      if (0 <= diff && diff < ALPHABET_COUNT) {
         letters[diff]--;
         if (letters[diff] < 0) {
            is_anagram = false;
            break;
         }
      }

      len2++;
   }

   if (is_anagram) {
      printf("The words are anagrams.\n");
   } else {
      printf("The words are not anagrams.\n");
   }

   return 0;
}