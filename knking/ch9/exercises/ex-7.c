/*
   a), b), c), d), e) are legal ✔️
*/

int f(int a, int b) { return 22; }

int main(void) {
   int i;
   double x;
   i = f(83, 12);
   x = f(83, 12);
   i = f(3.15, 9.28);
   x = f(3.15, 9.28);
   f(83, 12);

   return 0;

}