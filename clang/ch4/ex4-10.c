#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // for atof()
#include <math.h>
#include "../util.h"

#define MAXOP 100 // maximum of operand/operator
#define NUMBER '0' // signal that a number was found
#define LAST '$'
#define EXP 'e'
#define SINE 's'

int getop(char []);


char line[MAXLINE];


// reverse Polish calculator
// int main()
// {
//
// }
int main()
{
   getLine(line, MAXLINE);
   int type;
   double op2;
   char s[MAXOP];
   double last = 0.0;
   while ((type = getop(s)) != '\0') {
      switch (type) {
         case NUMBER: push(atof(s)); break;
         case LAST: push(last); break;
         case '+': push(pop() + pop()); break;
         case '*': push(pop() * pop()); break;
         case '-':
            op2 = pop();
            push(pop() - op2);
            break;
         case '/':
            op2 = pop();
            if (op2 != 0.0) push(pop() / op2);
            else printf("error: zero divisor\n");
            break;
         case '%':
            op2 = pop();
            if (op2 != 0.0) push((int)pop() % (int)op2);
            else printf("error: zero division is undefined\n");
            break;
         case '^':
            op2 = pop();
            push(pow(pop(), op2));
            break;
         case EXP:
            push(exp(pop()));
            break;
         case SINE:
            push(sin(pop()));
            break;
         case '\n':
            last = pop();
            printf("\t%.8g\n", last);
            break;
         default:
            printf("error: unknown command %s\n", s);
            break;
      }
   }
   return 0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);
void ungets(char s[]);

// get next operator or numeric operand
int getop(char s[])
{
   int i, c, start_i = 0;
   bool isneg = false;
   while ((s[0] = c = getch()) == ' ' || c == '\t')
      ;
   s[1] = '\0';

   if (!isdigit(c) && c != '.' && c != '-')
      return c; // not a number

   if (c == '-') {
      int d = getch();
      if (isdigit(d) || d == '.') {
         s[2] = '\0';
         s[1] = d;
         s[0] = c;
         c = d;
         start_i = 1;
      } else {
         ungetch(d);
         return c;
      }
   }

   i = start_i;
   if (isdigit(c))   // collect integer part
      while (isdigit(s[++i] = c = getch()))
         ;

   if (c == '.') // collect fraction part
      while (isdigit(s[++i] = c = getch()))
         ;

   s[i] = '\0';
   if (c != EOF) ungetch(c);

   return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE]; // buffer for ungetch
int bufp = 0; // next free position in buf

int getch(void) // get a (possibly pushed back) character
{
   return line[bufp++];
}

void ungetch(int c) // push character back on line
{
   if (bufp >= MAXLINE) printf("ungetch: end of line reached\n");
   else line[--bufp] = c;
}

void ungets(char s[])
{
   int i = 0;
   while (s[i]) ungetch(s[i++]);
}
