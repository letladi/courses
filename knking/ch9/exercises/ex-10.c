// a) ✔️
int largest(int n, int a[n])
{
   int max = a[0];
   for (int i = 1; i < n; i++) {
      if (a[i] > max) max = a[i];
   }
   return max;
}

// b) ❌ (more correct to probably return an int since values are integers)
double average(int n, int a[n])
{
   double sum = 0;
   for (int i = 0; i < n; i++) sum += a[i];
   return sum / n;
}

// c) ✔️
int num_pos(int n, int a[n])
{
   int count = 0;
   for (int i = 0; i < n; i++) 
      if (a[i] > 0) count++;
   return count;
}