int binsearch(int x, int v[], int n)
{
   int low, high, mid;

   low = 0;
   high = n - 1;

   while (low <= high) {
      mid = (low + high) / 2;
      int diff = x - v[mid];
      if (diff) {
         low = (diff > 0) ? (mid + 1) : low;
         high = (diff < 0) ? (mid - 1) : high;
      } else {
         return mid;
      }
   }
   return -1;
}
