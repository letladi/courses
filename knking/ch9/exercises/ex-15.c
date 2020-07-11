double median(double x, double y, double z)
{
   double med;
   if (x <= y && y <= z) med = y;
   else if (x <= z && z <= y) med = z;
   else med = x;

   return med;
}

// ❌ (was not supposed to total re-write the function)

double median(double x, double y, double z)
{
   double result;
   if (x <= y)
      if (y <= z) result = y;
      else if (x <= z) result = z;
      else result = x;
   else {
      if (z <= y) result = y;
      else if (x <= z) result = x;
      else result = z;
   }
   return result;
}