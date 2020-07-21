#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define LEN 100

bool is_palindrome(char a[], int n)
{
   for (int i = 0, j = n - 1; j >= i; i++, j--) {
      if (a[i] != a[j]) return false;
   }
   return true;
}

int main(void)
{
   char msg[LEN], c;
   bool is_letter;
   printf("Enter a message: ");
   int i = 0;
   while ((c = getchar()) != '\n' && (i < LEN)) {
      c = tolower(c);
      is_letter = ('a' <= c && c <= 'z');
      if (is_letter) msg[i++] = c;
   }

   if (is_palindrome(msg, i)) {
      printf("Palindrome\n");
   } else {
      printf("Not a palindrome\n");
   }

   return 0;
}