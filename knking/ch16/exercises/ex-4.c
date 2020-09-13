#include <stdio.h>

// a)
typedef struct { double real, imaginary; } Complex;

// c)
Complex make_complex(double r, double i)
{
   return (Complex) { r, i };
}

// d
Complex add_complex(Complex a, Complex b)
{
   return (Complex) { a.real + b.real, a.imaginary + b.imaginary };
}

int main(void)
{
   // b
   Complex c1, c2, c3;
   Complex c4 = make_complex(4, 4);
   printf("c4.real = %f, c4.imaginary = %f\n", c4.real, c4.imaginary);
   Complex c5 = add_complex(c4, make_complex(2, 2));
   printf("c5.real = %f, c5.imaginary = %f\n", c5.real, c5.imaginary);

   return 0;
}


