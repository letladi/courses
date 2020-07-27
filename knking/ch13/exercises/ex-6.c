#include <stdio.h>
#include <stdbool.h>

void censor(char *str)
{
   bool in_word = false;
   int o_count = 0;
   while (*str) {
      if (in_word) {
         if (*str == 'o') o_count++;
         else {
            in_word = false;
            o_count = 0;
         }
         if (o_count == 2) {
            *(str - 2) = *(str - 1) = *str = 'x';
            in_word = false;
            o_count = 0;
         }
      } else {
         if (*str == 'f') in_word = true;
      }
      str++;
   }
}

// 6.
// void censor(char s[])
// {
//    int i;
//    for (i = 0; s[i]; i++) {
//       isn't it an error to read past an array? s[i + 2] coule be past the array if s[i] is the last character
//       if (s[i] == 'f' && s[i + 1] == 'o' && s[i + 2] == 'o')
//          s[i] = s[i + 1] = s[i + 2] = 'x';
//    }
// }

int main(void)
{
   // char name1[] = "foo";
   // char name2[] = "food fool";
   // censor(name1);
   // censor(name2);
   // printf("%s\n", name1);
   // printf("%s\n", name2);

   char s[2] = "le";

   s[5];

   return 0;
}
