#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define ALPHABET_COUNT 26
#define WORD_LEN_MAX 45 // https://en.wikipedia.org/wiki/Longest_word_in_English#:~:text=The%20longest%20word%20in%20any,is%20the%20same%20as%20silicosis.

void read_word(int counts[ALPHABET_COUNT])
{
   printf("Enter word: ");
   char c;
   int len = 0, diff;
   while ((c = getchar()) != '\n' && len < ALPHABET_COUNT) {
      c = tolower(c);
      diff = c - 'a';
      if (0 <= diff  && diff < ALPHABET_COUNT) {
         counts[diff]++;
      }
      len++;
   }
}

bool equal_array(int counts1[ALPHABET_COUNT], int counts2[ALPHABET_COUNT])
{
   int len = 0;
   while (len < ALPHABET_COUNT) {
      if (counts1[len] != counts2[len]) return false;
      len++;
   }
   return true;
}

int main(void)
{
   int word1[ALPHABET_COUNT] = {0},
       word2[ALPHABET_COUNT] = {0};

   read_word(word1);
   read_word(word2);
   
   if (equal_array(word1, word2)) {
      printf("The words are anagrams.\n");
   } else {
      printf("The words are not anagrams.\n");
   }

   return 0;
}