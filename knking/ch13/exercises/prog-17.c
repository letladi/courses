#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define LEN 100

bool is_palindrome(const char *message)
{
   const char *p = message + strlen(message) - 1;
   bool is_letter;
   char a, b;
   while (p >= message) {
      a = tolower(*message);
      b = tolower(*p);

      is_letter = 'a' <= a && a <= 'z';
      if (!is_letter) {
         message++;
         continue;
      }
      is_letter = 'a' <= b && b <= 'z';
      if (!is_letter) {
         p--;
         continue;
      }
      
      if (a != b) 
         return false;

      message++;
      p--;
   }
   return true;
}

int main(void)
{
   char msg[LEN] = {0}, c;
   printf("Enter a message: ");
   char *i = msg, *end = msg + LEN;
   while ((c = getchar()) != '\n' && (i < end)) {
      *i++ = c;
   }

   if (is_palindrome(msg)) {
      printf("Palindrome\n");
   } else {
      printf("Not a palindrome\n");
   }

   return 0;
}