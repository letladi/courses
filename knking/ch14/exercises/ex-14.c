// space; #define N = 10 is an error ✔️
// space ✔️
// space ✔️
// space ✔️
// space ✔️
// space ✔️
// space ✔️

int main(void)
{
   int a[N = 10], i, j, k, m; // improper definition of N results in erronious definition of array a
   i = j;
   i = 10 * j + 1; // without brackets the wrong value is computed
   i = j - k; // ❌
   i = SQR(j) * SQR(j); // the double call of the macro is not valid ❌
   i = ((j * j) * j);
   i = jk; // an error since no variable jk exists ✔️
   puts("xy");// ❌ puts("x" "y");

   // space for #undef SQR
   i = SQR(j); // an error since now SQR is undefined ✔️
   // space #define SQR
   i = ; // an error since SQR now is empty definition ❌ i = (j);

   return 0;

   
}