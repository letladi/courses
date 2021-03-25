#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../../../util.h"
#define MAX_WORD_LEN 20
#define WORD_LIST_INCR 5

int compare_word(const void*, const void*);

int main(void) {
   char *word;

   char **word_list = malloc(sizeof(char*) * WORD_LIST_INCR);
   int size = WORD_LIST_INCR;
   size_t len = 0, word_len;

   do {
      printf("Enter word: ");
      word = malloc(sizeof(char) * MAX_WORD_LEN);
      read_line(word, MAX_WORD_LEN);
      
      word_len = strlen(word);
      if (word_len > 0) {
         // if space is full, resize first
         if (len == size) {
            char* *new_word_list = realloc(word_list, sizeof(char*) * (size + WORD_LIST_INCR));
            if (new_word_list != NULL) {
               word_list = new_word_list;
               size += WORD_LIST_INCR;
            } else {
               free(word);
               break;
            }
         } 

         word_list[len++] = word;
      } else {
         break;
      }
   } while (true);

   printf("\nIn sorted order: ");
   qsort(word_list, len, sizeof(char*), compare_word);
   for (int j = 0; j < len; j++) {
      printf("%s ", word_list[j]);
   }
   putchar('\n');

   return 0;
}

int compare_word(const void* word1, const void* word2)
{ 
   const char* pt1 = *(const char**)word1;
   const char* pt2 = *(const char**)word2;
   return strcmp(pt1, pt2);  
}