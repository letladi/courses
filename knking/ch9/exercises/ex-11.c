float compute_GPA(char grades[], int n)
{
   int avg = 0, g;
   for (int i = 0; i < n; i++) {
      g = grades[i];
      switch(g) {
         case 'A': g = 4; break;
         case 'B': g = 3; break;
         case 'C': g = 2; break;
         case 'D': g = 1; break;
         case 'F': default: g = 0; break;
      }
      avg += g;
   }
   return avg / n;
}