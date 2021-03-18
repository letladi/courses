#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line.h"

#define MAX_LINE_LEN 60

// char line[MAX_LINE_LEN+1];// 
typedef struct word {
   char* val;
   int len;
   struct word *next;
} word;
int line_len = 0;
word *line;
word *tail;
int num_words = 0;

void clear_line(void)
{
   // line[0] = '\0';
   line_len = 0;
   num_words = 0;

   word *pt = line;
   word *prev = NULL;
   while (pt != NULL) {
      prev = pt;
      pt = pt->next;
      free(prev->val);
      free(prev);
   }
   line = NULL;
}

void add_word(const char *wrd)
{
   char *new_word;
   int new_word_len = 0;
   int wrd_len = strlen(wrd);
   if (num_words > 0) {
      new_word = malloc(sizeof(char) * (wrd_len+ 2));
      new_word[new_word_len++] = ' ';
      strcat(new_word, wrd);
      // line[line_len] = ' ';
      // line[line_len+1] = '\0';
      // line_len++;
   } else {
      new_word = malloc(sizeof(char) * (wrd_len + 1));
      strcpy(new_word, wrd);
   }
   new_word_len += wrd_len;
   

   word *line_word = malloc(sizeof(word));
   line_word->next = NULL;
   line_word->val = new_word;
   line_word->len = new_word_len;

   if (line) {
      tail->next = line_word;
      tail = line_word;
   } else {
      line = line_word;
      tail = line_word;
   }
  
   // strcat(line, word);
   // line_len += strlen(word);
   line_len += new_word_len;
   num_words++;
}

int space_remaining(void)
{
   return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
   int extra_spaces, spaces_to_insert, i, j;
   extra_spaces = MAX_LINE_LEN - line_len;
   // for (i = 0; i < line_len; i++) {
   //    if (line[i] != ' ') putchar(line[i]);
   //    else {
   //       spaces_to_insert = extra_spaces / (num_words - 1);
   //       for (j = 1; j <= spaces_to_insert + 1; j++) putchar(' ');
   //       extra_spaces -= spaces_to_insert;
   //       num_words--;
   //    }
   char *ch;
   int count = 0;
   for (word *pt = line; pt != NULL && count < line_len; pt = pt->next, num_words--, count++) {
      ch = &pt->val[0];
      if (*ch == ' ') {
         spaces_to_insert = extra_spaces / (num_words - 1);
         for (j = 1; j <= spaces_to_insert + 1; j++) putchar(' ');
         extra_spaces -= spaces_to_insert;
         ch++;
      } 
      for ( ; *ch != '\0'; ch++) putchar(*ch);

   }
   putchar('\n');
}

void flush_line(void)
{
   // if (line_len > 0) puts(line);
   if (line_len > 0) {
      word *pt = line;
      while (pt != NULL) {
         char *ch = &pt->val[0];
         while (*ch) {
            putchar(*ch);
            ch++;
         }
         pt = pt->next;
      }
   }
   putchar('\n');
}