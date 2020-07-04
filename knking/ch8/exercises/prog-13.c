#include <stdio.h>
#define LAST_NAME_LEN 20

int main(void)
{
   char c;
   char last_name[LAST_NAME_LEN];
   char initial;

   printf("Enter a first and last name: ");
   _Bool on_last_name = 0, has_first_initial = 0;
   int last_name_len = 0;
   while (last_name_len < LAST_NAME_LEN) {
      if (!has_first_initial) {
         initial = getchar();
         has_first_initial = c != ' ';
      } else if (has_first_initial && !on_last_name) {
         c = getchar();
         on_last_name = c == ' ';
      } else if (on_last_name) {
         c = getchar();
         _Bool is_space = c == ' ' || c == '\n' || c == '\t';
         if (is_space) {
            if (last_name_len >= 1) break;
            else continue;
         }
         last_name[last_name_len++] = c;
      }
   }

   for (int i = 0; i < last_name_len; i++) printf("%c", last_name[i]);

   printf(", %c.\n", initial);

   return 0;
}