#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define LEN 100

bool is_palindrome(char a[], int n)
{
   for (char *i = a, *j = a + n - 1; j >= i; i++, j--) {
      if (*i != *j) return false;
   }
   return true;
}

int main(void)
{
   char msg[LEN], c;
   bool is_letter;
   printf("Enter a message: ");
   char *i = msg, *end = msg + LEN;
   while ((c = getchar()) != '\n' && (i < end)) {
      c = tolower(c);
      is_letter = ('a' <= c && c <= 'z');
      if (is_letter) *i++ = c;
   }

   if (is_palindrome(msg, i - msg)) {
      printf("Palindrome\n");
   } else {
      printf("Not a palindrome\n");
   }

   return 0;
}