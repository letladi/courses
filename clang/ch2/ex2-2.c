for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; i++)
{
   s[i] = c;
}

// loop without && and ||
int max = lim - 1;
for (i = 0; i < max; i++) {
   switch (c = getchar())
   {
      case '\n': case EOF: break;
      default: s[i] = c; continue;
   }
   break; 
}