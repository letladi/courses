#include <stdio.h>
#include <limits.h>
#define ALPHABET_COUNT 26

int main()
{
   int c;
   int wordc[ALPHABET_COUNT];
   int max = INT_MIN;

   for (int i = 0; i < ALPHABET_COUNT; i++) wordc[i] = 0;

   while ((c = getchar()) != EOF) {
      if ('a' <= c && c <= 'z') {
         int index = c - 'a';
         wordc[index]++;
         if (wordc[index] > max) max = wordc[index];
      }
   }

   printf("\n\n\n");
   while (max) {
      printf(" | ");
      for (int i = 0; i < ALPHABET_COUNT; i++) {
         if (wordc[i] >= max) {
            printf(".");
            wordc[i]--;
         } else {
            printf(" ");
         }
         printf(" | ");
      }
      printf("\n");
      max--;
   }

   int ch = 'a';
   printf(" |");
   for (int i = 0; i < ALPHABET_COUNT; i++) {
      printf(" %c |", ch++);
   }
   printf("\n\n");
}
