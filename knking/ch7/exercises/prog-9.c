#include <stdio.h>
#include <ctype.h>

int main(void)
{
   short hr, min;
   char c;
   printf("Enter a 12-hour time: ");
   scanf("%hd : %hd %c", &hr, &min, &c);
   c = toupper(c);
   _Bool is_am = c == 'A';

   if (is_am) {
      if (hr == 12) 
         hr = 0;
   } else {
      hr += 12;
   }

   printf("Equivalent 24-hour time: %hd:%.2hd\n", hr, min);

   return 0;
}