/*
   the program could contain i outside main. Another i inside main (either as a parameter or local variable)
   It could also contain i in any number of blocks defined in main.
   Thus the program can contain at least 3 i's
*/

int i;

int main(void) {
   int i;

   {
      int i;
   }

   {
      int i;
   }

   {
      int i;
   }

   {
      int i;
   }

   {
      int i;
   }

   {
      int i;
   }

   return 0;
}