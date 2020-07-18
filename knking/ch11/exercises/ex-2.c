/**
 * e) ✔️, f) ✔️, i) ✔️ (legal if q is pointing somewhere)
*/

int main(void)
{
   int i = 10;
   int *p, *q;
   // a) legal, but compiles with a warning
   // p = i;
   // b) legal, but compiles with a warning
   // *p = &i;
   // c) not legal; is an error
   // &p = q;
   // d) legal, but compiles with an error
   // p = &q;
   // e) Legal
   // p = *&q;
   // f) Legal
   // p = q;
   // g) legal, but compiles with a warning and crashes the program
   // p = *q;
   // h) legal, but compiles with warnings
   // *p = q;
   // i) legal, but compiles with a warning and causes segmentation faults
   // q = &i;
   // *p = *q;

   return 0;
}