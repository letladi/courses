#include <stdio.h>

int main(void)
{
   int s1, s2, s3; // different sections of a phone number
   printf("Enter phone number [(xxx) xxx-xxxx]: ");
   scanf("( %d ) %d - %d", &s1, &s2, &s3);
   printf("You entered %d.%d.%d\n", s1, s2, s3);
   
   return 0;
}