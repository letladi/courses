/*
   for (d = 2; d * d < n; d++) {
      if (n % d == 0) break;
   }
   ❌
   for (d = 2; d * d <= n; d++)
      if (n % d == 0) break;
*/