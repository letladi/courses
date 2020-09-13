#include <stdio.h>

// a)
struct complex {
   double real, imaginary;
};

// c) 
struct complex make_complex(double r, double i)
{
   return (struct complex) { r, i };
}

// d)
struct complex add_complex(struct complex a, struct complex b)
{
   struct complex ret = { a.real + b.real, a.imaginary + b.imaginary };
   return ret;
}

int main(void)
{
   // b
   struct complex c1, c2, c3;
   struct complex c4 = make_complex(4, 4);
   printf("c4.real = %f, c4.imaginary = %f\n", c4.real, c4.imaginary);
   struct complex c5 = add_complex(c4, make_complex(2, 2));
   printf("c5.real = %f, c5.imaginary = %f\n", c5.real, c5.imaginary);

   return 0;
}

