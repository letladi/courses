#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // for atof()
#include <math.h>
#include "../util.h"
#include "../ch4/calculator/stack.h"

#define MAXOP 100 // maximum of operand/operator
#define NUMBER '0' // signal that a number was found
#define LAST '$'
#define EXP 'e'
#define SINE 's'

// reverse Polish calculator
int main(int argc, char *argv[])
{
   // getLine(line, MAXLINE);
   int type;
   double op2;
   char s[MAXOP];
   double last = 0.0;
   argv++;
   bool onlast = false;
   while ((--argc > 0) || onlast) {
      if (onlast) {
         type = '\n';
      } else {
         type = getop(*argv);
      }

      switch (type) {
         case NUMBER: push(atof(*argv)); break;
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
            printf("error: unknown command %s\n", *argv);
            break;
      }
      argv++;
      onlast = (*argv == NULL);
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
   int i, c, start_i = 0, j = 0;
   bool isneg = false;
   while ((c = s[j++]) == ' ' || c == '\t')
      ;

   if (!isdigit(c) && c != '.' && c != '-')
      return c; // not a number

   bool isnum = true;
   if (c == '-') {
      isnum = true;
      int d = s[j++];
      if (isdigit(d) || d == '.') {
         c = d;
      } else {
         return c;
      }
   }

   if (isdigit(c))   // collect integer part
      while ((c = s[j++]) && isnum) {
         isnum = isdigit(c);
      }

   if (c == '.') // collect fraction part
      while (c = s[j++] && isnum) {
         isnum = isdigit(c);
      }

   if (!isnum) return c;


   return NUMBER;
}
