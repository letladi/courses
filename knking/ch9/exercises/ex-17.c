int fact(int n)
{
   int ret = 1;
   while (n > 1) ret *= n--;
   return ret;
}

// ✔️