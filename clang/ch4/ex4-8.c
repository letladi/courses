int prevC = '\0';

int getch(void) // get a (possibly pushed back) character
{
   return prevC || getchar();
}

void ungetch(int c) // push character back on input
{
   prevC = c;
}
