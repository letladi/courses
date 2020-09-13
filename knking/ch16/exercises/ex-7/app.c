#include <stdio.h>
#include "../../../util.h"

struct fraction {
   int numerator, denominator;
};

// a)
struct fraction reduce(struct fraction fr)
{
   int cd = gcd(fr.numerator, fr.denominator);
   return (struct fraction) { 
      .numerator = fr.numerator / cd, 
      .denominator = fr.denominator / cd,
   };
}

// b)
struct fraction add(struct fraction f1, struct fraction f2)
{
   return reduce((struct fraction) {
      .denominator = f1.denominator * f2.denominator,
      .numerator = f1.numerator * f2.denominator + f1.denominator * f2.numerator
   });
}

// c)
struct fraction subtract(struct fraction f1, struct fraction f2)
{
   return reduce((struct fraction) {
      .denominator = f1.denominator * f2.denominator,
      .numerator = f1.numerator * f2.denominator - f1.denominator * f2.numerator
   });
}

// d)
struct fraction multiply(struct fraction f1, struct fraction f2)
{
   return reduce((struct fraction) {
      .denominator = f1.denominator * f2.denominator,
      .numerator = f1.numerator * f2.numerator
   });
}

// e)
struct fraction divide(struct fraction f1, struct fraction f2)
{
   return reduce((struct fraction) {
      .denominator = f1.denominator * f2.numerator,
      .numerator = f1.numerator * f2.denominator
   });
}


int main(void)
{
   struct fraction f1 = { 6, 12 };
   f1 = reduce(f1);
   printf("6/12 = %d/%d\n", f1.numerator, f1.denominator);

   struct fraction f2 = {1, 4};
   struct fraction added = add(f1,f2);
   printf("6/12+1/4 = %d/%d\n", added.numerator, added.denominator);

   struct fraction subtracted = subtract(f1, f2);
   printf("6/12-1/4 = %d/%d\n", subtracted.numerator, subtracted.denominator);

   struct fraction multiplied = multiply(f1, f2);
   printf("6/12*1/4 = %d/%d\n", multiplied.numerator, multiplied.denominator);

   struct fraction quotient = divide(f1, f2);
   printf("6/12 / 1/4 = %d/%d\n", quotient.numerator, quotient.denominator);

   return 0;
}
