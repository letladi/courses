#include <stdio.h>
#include <stdbool.h>
#define MSG_LEN 80
#define ALPHABET_COUNT 26

int main(void)
{
   char msg[MSG_LEN], c;
   int len = 0, diff;
   bool is_lower_case = false, is_upper_case = false;
   printf("Enter a message to be encrypted: ");
   while ((c = getchar()) != '\n' && (len < MSG_LEN)) {
      msg[len++] = c;
   }

   int shift_amt;
   printf("Enter shift amount (1-25): ");
   scanf(" %d", &shift_amt);

   // encrypt message
   printf("Encrypted message: ");
   int i = 0;
   while (i < len) {
      // test lower case 
      c = msg[i];
      diff = c - 'a';
      is_lower_case = 0 <= diff && diff < ALPHABET_COUNT;
      // test upper case 
      if (!is_lower_case) {
         diff = c - 'A';
         is_upper_case = 0 <= diff && diff < ALPHABET_COUNT;
      }

      if (is_lower_case) {
         c = (diff + shift_amt) % ALPHABET_COUNT + 'a'; 
      } else if (is_upper_case) {
         c = (diff + shift_amt) % ALPHABET_COUNT + 'A';
      }
      printf("%c", c);
      i++;
   }
   printf("\n");

   return 0;
}