// int getLine(char s[], int lim)
// {
//    int c, i;
//    i = 0;
//    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') s[i++] = c;
//    if (c == '\n') s[i++] = c;
//    s[i] = '\0';
//    return i;
// }

int getLine(char *s, int lim)
{
   int c;
   char *last = s + lim;
   char *start = s;
   while ((s < last) && (c = getchar()) != EOF && c != '\n') *s++ = c;
   if (c == '\n') *s++ = c;
   *s = '\0';
   return last - start;
}

void reverse(char s[])
{
   int c, i, j;
   for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
      c = s[i], s[i] = s[j], s[j] = c;
   }
}

void reverse(char *s)
{
   for (char c, *end = strlen(s) + s; s < end; s++, end--) {
      c = *s, *s = *end, *end = c;
   }
}
