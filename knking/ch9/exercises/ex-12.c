double inner_product(double a[], double b[], int n) 
{
   double prod = 1;
   for (int i = 0; i < n; i++) {
      prod = a[i] * b[i];
   }
   return prod;
}