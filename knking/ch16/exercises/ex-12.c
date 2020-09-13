union {
   double a;
   struct {
      char b[4];
      double c;
      int d;
   } e;
   char f[4];
} u;
// 4*1 + 8 * 4 = 16