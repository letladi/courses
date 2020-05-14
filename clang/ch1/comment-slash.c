#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "util.h"

#define MAX_PROGRAM_LEN 10000

int get_program(char s[], int lim);

bool is_multiline_comment_start(char s[], int i) {
   return s[i] == '/' && (s[i + 1] == '*');
}
bool is_multiline_comment_end(char s[], int i) {
   return s[i] == '*' && s[i + 1] == '/';
}
bool is_oneline_comment(char s[], int i) {
   return s[i] == '/' && s[i + 1] == '/';
}
bool is_string_boundary(char s[], int i) {
   bool is_boundary = (s[i] == '"');
   return (i == 0) ? is_boundary : is_boundary && (s[i - 1] != '\\');
}

void remove_comments(char prog[], int i)
{
   bool in_comment = false, in_string = false, in_one_line_comment = false;
   int deleteLen = 0;
   size_t deleteStart = 0;
   while (prog[i] != '\0') {
      if (is_oneline_comment(prog, i)) {
         int next_line_i = next_line_start_index(prog, i);
         if (next_line_i == i) {
            prog[i] = '\0';
            break;
         } else {
            splice(prog, i, next_line_i - 1);
         }
      } else if (is_multiline_comment_start(prog, i) && !in_string && !in_comment) {
         deleteStart = i;
         in_comment = true;
      } else if (is_multiline_comment_end(prog, i) && !in_string && in_comment) {
         splice(prog, deleteStart, i + 1);
         deleteStart = 0;
         in_comment = false;
      } else if (is_string_boundary(prog, i) && !in_comment) {
         in_string = !in_string;
      }
      i++;
   }
}
