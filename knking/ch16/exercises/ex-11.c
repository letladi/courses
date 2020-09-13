struct {
   double a;
   union {
      char b[4];
      double c;
      int d;
   } e;
   char f[4];
} s;
// 8 + 8 + 4*1 = 20 ✔️