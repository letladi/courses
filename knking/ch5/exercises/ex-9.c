/*
   Yes. the statements are equal ✔️
*/

#include <stdio.h>

int main(void)
{
   int score = 91;
   if (score >= 90) printf("A");
   else if (score >= 80) printf("B");
   else if (score >= 70) printf("C");
   else if (score >= 60) printf("D");
   else printf("F");

   score = 82;
   if (score >= 90) printf("A");
   else if (score >= 80) printf("B");
   else if (score >= 70) printf("C");
   else if (score >= 60) printf("D");
   else printf("F");

   score = 76;
   if (score >= 90) printf("A");
   else if (score >= 80) printf("B");
   else if (score >= 70) printf("C");
   else if (score >= 60) printf("D");
   else printf("F");

   score = 65;
   if (score >= 90) printf("A");
   else if (score >= 80) printf("B");
   else if (score >= 70) printf("C");
   else if (score >= 60) printf("D");
   else printf("F");
   
   score = 55;
   if (score >= 90) printf("A");
   else if (score >= 80) printf("B");
   else if (score >= 70) printf("C");
   else if (score >= 60) printf("D");
   else printf("F");

   printf("\n");

   score = 91;
   if (score < 60) printf("F");
   else if (score < 70) printf("D");
   else if (score < 80) printf("C");
   else if (score < 90) printf("B");
   else printf("A");

   score = 82;
   if (score < 60) printf("F");
   else if (score < 70) printf("D");
   else if (score < 80) printf("C");
   else if (score < 90) printf("B");
   else printf("A");

   score = 76;
   if (score < 60) printf("F");
   else if (score < 70) printf("D");
   else if (score < 80) printf("C");
   else if (score < 90) printf("B");
   else printf("A");

   score = 65;
   if (score < 60) printf("F");
   else if (score < 70) printf("D");
   else if (score < 80) printf("C");
   else if (score < 90) printf("B");
   else printf("A");
   
   score = 55;
   if (score < 60) printf("F");
   else if (score < 70) printf("D");
   else if (score < 80) printf("C");
   else if (score < 90) printf("B");
   else printf("A");

   printf("\n");

   return 0;
}