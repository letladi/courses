/*
   // a) ✔️
   long long_max(long x, long y)
   {
      return x > y ? x : y;
   }

   // b) 
   for 'unsigned long', the expansion of the function
   signature would be 'unsigned long unsigned long_max(unsigned long x, unsigned long y)'
   which is not a valid return type.

   // c) ❌
   we can add extra parameters to GENERIC_MAX and then concatenate each the parameters to be the prefix name of the function

   Use a type definition 🙂
   typedef unsigned long ULONG;

*/