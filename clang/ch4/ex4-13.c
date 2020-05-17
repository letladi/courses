#include <stdio.h>

int reverse_impl(char s[], int n)
{
   int i;
   if (s[n] == '\0') {
      i = -1;
   } else {
      int c = s[n];
      i = reverse_impl(s, n + 1);
      s[i] = c;
   }
   return i + 1;
}

void reverse(char s[])
{
   int i = reverse_impl(s, 0);
}

int main()
{
   char s[20] = "letladi";
   char s2[20] = "sebesho";
   reverse(s);
   reverse(s2);
   printf("reverse('letladi') = %s\n", s);
   printf("reverse('sebesho') = %s\n", s2);
}
