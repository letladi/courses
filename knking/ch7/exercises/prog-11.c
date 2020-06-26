#include <stdio.h>

int main(void)
{
   char f, c, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14;

   printf("Enter a first and last name: ");
   _Bool on_last_name = 0, has_first_initial = 0;
   int i = 1;
   while (1) {
      if (!has_first_initial) {
         c = getchar();
         f = c;
         has_first_initial = c != ' ';
      } else if (has_first_initial && !on_last_name) {
         c = getchar();
         on_last_name = c == ' ';
      } else if (on_last_name) {
         c = getchar();
         _Bool is_space = c == ' ' || c == '\n' || c == '\t';
         if (is_space) {
            if (i > 1) break;
            else continue;
         }
         if (is_space && (i > 1)) break;
         switch(i) {
            case 1: c1 = c; break;
            case 2: c2 = c; break;
            case 3: c3 = c; break;
            case 4: c4 = c; break;
            case 5: c5 = c; break;
            case 6: c6 = c; break;
            case 7: c7 = c; break;
            case 8: c8 = c; break;
            case 9: c9 = c; break;
            case 10: c10 = c; break;
            case 11: c11 =  c; break;
            case 12: c12 = c; break;
            case 13: c13 = c; break;
            case 14: c14 = c; break;
         }
         i++;
      }
   }

   int count = 1;
   while (count < i) {
      char d;
      switch (count) {
         case 1: d = c1; break;
         case 2: d = c2; break;
         case 3: d = c3; break;
         case 4: d = c4; break;
         case 5: d = c5; break;
         case 6: d = c6; break;
         case 7: d = c7; break;
         case 8: d = c8; break;
         case 9: d = c9; break;
         case 10: d = c10; break;
         case 11: d = c11; break;
         case 12: d = c12; break;
         case 13: d = c13; break;
         case 14: d = c14; break;
      }
      printf("%c", d);
      count++;
   }

   printf(", %c\n", f);

   return 0;
}