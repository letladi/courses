#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "util.h"
// remove all the characters betwee 'start' and 'end' inclusive
int splice(char s[], int start, int end)
{
   if (s[end] == '\0'|| s[end + 1] == '\0') s[start] = '\0';
   end++; // we start on the next character that must not be deleted
   int num_removed = 0;
   while (s[end] != '\0') {
      s[start++] = s[end++];
      num_removed++;
   }
   s[start] = s[end];
   return num_removed;
}

int next_line_start_index(char s[], int start)
{
   bool found = false;
   int init_val = start;
   while (!found && s[start] != '\0') {
      if (s[start] == '\n') found = true;
      start++;
   }
   return found ? start : init_val;
}

void copy_str(char dest[], char src[])
{
   int i = 0;
   while (src[i] != '\0') {
      dest[i] = src[i];
      i++;
   }
   dest[i] = '\0';
}

int strLen(char s[])
{
   int i = -1;
   while (s[++i]);
   return i;
}