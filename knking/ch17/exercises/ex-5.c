/**
 * b, c, d are legal ❌ d is actually illegal, d is not a pointer, so we cannot use -> to access its member c
 */ 

struct {
   union {
      char a, b;
      int c;
   } d;
   int e[5];
} f, *p = &f;
