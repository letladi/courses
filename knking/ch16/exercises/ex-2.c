/**
 * a) struct { double real, imaginary; } c1, c2, c3; ✔️
 * b) struct { double real, imaginary; } c1 = {0.0, 1.0}, c2 = {1.0, 0.0}, c3; ✔️
 * c) c1.real = c2.real; c1.imaginary = c2.imaginary; 
 *    This can be done in one statement;
 *    c1 = c2; ✔️
 * d) c3.real = c1.real + c2.real; c3.imaginary = c1.imaginary + c2.imaginary; ✔️
*/ 