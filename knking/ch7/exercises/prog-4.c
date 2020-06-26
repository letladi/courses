#include <stdio.h>

int main(void)
{
   char c;
   char i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15;
   int nums = 11, count = 0;
   
   printf("Enter phone number: ");
   while (1) {
      c = getchar();
      if (c == '\n') break;

      switch (c) {
         case 'A': case 'a': case 'B': case 'b': case 'C': case 'c': c = '2'; break;
         case 'D': case 'E': case 'F': c = '3'; break;
         case 'G': case 'H': case 'I': c = '4'; break;
         case 'J': case 'K': case 'L': c = '5'; break;
         case 'M': case 'N': case 'O': c = '6'; break;
         case 'P': case 'R': case 'S': c = '7'; break;
         case 'T': case 'U': case 'V': c = '8'; break;
         case 'W': case 'X': case 'Y': c = '9'; break;
      }
      count++;
      switch (count) {
         case 1: i1 = c; break;
         case 2: i2 = c; break;
         case 3: i3 = c; break;
         case 4: i4 = c; break;
         case 5: i5 = c; break;
         case 6: i6 = c; break;
         case 7: i7 = c; break;
         case 8: i8 = c; break;
         case 9: i9 = c; break;
         case 10: i10 = c; break;
         case 11: i11 = c; break;
         case 12: i12 = c; break;
         case 13: i13 = c; break;
         case 14: i14 = c; break;
         case 15: i15 = c; break;
      }
      
   }

   int j = 1;
   while (j <= count) {
      char d;
      switch(j) {
         case 1:  d = i1; break;
         case 2: d = i2; break;
         case 3: d = i3; break;
         case 4: d = i4; break;
         case 5: d = i5; break;
         case 6: d = i6; break;
         case 7: d = i7; break;
         case 8: d = i8; break;
         case 9: d = i9; break;
         case 10: d = i10; break;
         case 11: d = i11; break;
         case 12: d = i12; break;
         case 13: d = i13; break;
         case 14: d = i14; break;
         case 15: d = i15; break;
      }
      printf("%c", d);
      j++;
   }
   printf("\n");
   
   return 0;
}