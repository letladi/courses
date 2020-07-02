function gcd(x, y) {
   while (x != y) {
      if (x > y) {
         x = x - y;
      } else {
         y = y - x;
      }
   }
   return x;
}

console.log("gcd(190, 34) = ", gcd(190, 34));
