#include <stdio.h>

int main(void) 
{
   int hr, min;
   printf("Enter a 24-hour time: ");
   scanf("%d : %d", &hr, &min);

   int new_hr;
   switch(hr) {
      case 0: case 12: new_hr = 12; break;
      case 1: case 13: new_hr = 1; break;
      case 2: case 14: new_hr = 2; break;
      case 4: case 16: new_hr = 4; break;
      case 5: case 17: new_hr = 5; break;
      case 6: case 18: new_hr = 6; break;
      case 7: case 19: new_hr = 7; break;
      case 8: case 20: new_hr = 8; break;
      case 9: case 21: new_hr = 9; break;
      case 10: case 22: new_hr = 10; break;
      case 11: case 23: new_hr = 11; break;
   }

   
   printf("Equivalent 12-hour time: %.2d:%.2d\n", new_hr, min);

   return 0;
}

/*
 ❌
int main(void)
{
   int hr, min;
   printf("Enter a 24-hour time: ");
   scanf("%d : %d", &hr, &min);

   printf("Equivalent 12-hour time: ");
   if (hr == 0) printf("12:%.2d AM", min);
   else if (hr == 12) printf("12:%.2d PM", min);
   else if (hr < 12) printf("%.2d:%.2d AM", hr, min);
   else printf("%.2d:%.2d PM", hr - 12, min);

   printf("\n");

   return 0;
}
*/