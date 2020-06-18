#include <stdio.h>

// int main(void)
// {
//    int d1, d2;
   
//    printf("Enter numerical grade: ");
//    scanf("%1d%1d", &d1, &d2);

//    printf("Letter grade: ");
//    switch(d1) {
//       case 9: printf("A"); break;
//       case 8: printf("B"); break;
//       case 7: printf("C"); break;
//       case 6: printf("D"); break;
//       case 5: printf("F"); break;
//    }
//    printf("\n");

//    return 0;
// }

// ❌ The above solution is not correct because it does not give allow the grade 100%

int main(void)
{
   int grade;
   printf("Enter numerical grade: ");
   scanf("%d", &grade);

   printf("Letter grade: ");
   switch(grade / 10) {
      case 10: case 9: printf("A"); break;
      case 8: printf("B"); break;
      case 7: printf("C"); break;
      case 6: printf("D"); break;
      default: printf("F"); break;
   }
   printf("\n");

   return 0;
}
