#include <stdio.h>
#include <stdbool.h>
#define MSG_LEN 80
#define ALPHABET_COUNT 26

void encrypt(char *msg, int shift)
{
   int diff;
   char c;
   bool is_lower_case = false, is_upper_case = false;
   while (*msg) {
      // test lower case 
      diff = *msg - 'a';
      is_lower_case = 0 <= diff && diff < ALPHABET_COUNT;
      // test upper case 
      if (!is_lower_case) {
         diff = *msg - 'A';
         is_upper_case = 0 <= diff && diff < ALPHABET_COUNT;
      }

      if (is_lower_case) {
         *msg = (diff + shift) % ALPHABET_COUNT + 'a'; 
      } else if (is_upper_case) {
         *msg = (diff + shift) % ALPHABET_COUNT + 'A';
      }
      msg++;
   }
}

int main(void)
{
   char msg[MSG_LEN], c;
   int len = 0;
   
   printf("Enter a message to be encrypted: ");
   while ((c = getchar()) != '\n' && (len < MSG_LEN)) {
      msg[len++] = c;
   }

   int shift_amt;
   printf("Enter shift amount (1-25): ");
   scanf(" %d", &shift_amt);
   // encrypt message
   encrypt(msg, shift_amt);
   printf("Encrypted message: %s\n", msg);

   return 0;
}