/**
 * a), d), g), ❌
 * 
 * 
 */ 

/*
   In this case what is meant by an alias for i? A variable that has the same value as i?
*/

#include <stdio.h>

int main(void)
{
   int i = 10;
   int *p = &i;
   printf("&i = %p\n\n", &i); 
   printf("a) *p = %d\n", *p); // a) This is the value of i
   printf("b) &p = %p\n", &p); // b) ❌. In this &p is a pointer to a pointer, that is a pointer to p
   printf("c) *&p = %p\n", *&p); // c) this is a pointer to i (the value of p)
   printf("d) &*p = %p\n", &*p); // d) this is a pointer to i (the value of p)
   // printf("e) *i = %p\n", *i); // e) ❌. This is actually an error
   printf("f) &i = %p\n", &i); // f) This is i's address (pointer to i)
   printf("g) *&i = %d\n", *&i); // g) This is the value of i (not necessairy its alias)
   // printf("h) &*i = %d\n", &*i); // h) ❌. This is an error
   return 0;
}