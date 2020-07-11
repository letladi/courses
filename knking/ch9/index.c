#include <stdio.h>

void print_count(int n)
{
   printf("T minus %d and counting\n", n);
}

// int sum_array(int n, int a[n]) 
// {

// }

// int concatenate(int m, int n, int a[m], int b[n], int c[m+n])
// {

// }

double average(a, b)
double a, b;
{
   return (a + b) / 2;
}

// double make(int x) {
//    return print_count(x);
// }


int main(void)
{
   // printf("%f\n", make(1, 2, 3, 5));
   return 1;
}

int sum_two_dimensional_array(int n, int m, int a[n][m])
{
   int i, j, sum = 0;

   for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
         sum += a[i][j];
      }
   }

   return sum;
}