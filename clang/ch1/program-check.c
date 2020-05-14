#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "util.h"
#include "lines.h"

bool matching_syms(char op, char cl)
{
   return (
      (op == '\'' && cl == '\'') ||
      (op == '"' && cl == '"') ||
      (op == '{' && cl == '}') ||
      (op == '(' && cl == ')') ||
      (op == '[' && cl == ']')
   );
}

bool is_opening_sym(char c)
{
   switch (c) {
      case'\'': case '"': case '{': case '(': case '[': return true;
      default: return false;
   }
}

bool is_closing_sym(char c)
{
   switch (c) {
      case ')': case '}': case '"': case '\'': case ']': return true;
      default: return false;
   }
}

int main() {
   char prog[MAXLINE] = "char *s = \"letadi sebesho\";\nvoid print(char *s) {\n scanf(s);\n}\nint i = 25;\nj = 20;\n";
   char checker[MAXLINE / 2];

   char copy_prog[MAXLINE];
   copy_str(copy_prog, prog);
   remove_comments(copy_prog, 0);

   int i = 0, c, checkIndex = -1;

   while ((c = copy_prog[i]) != '\0') {
      if (is_closing_sym(c)) {
         if ((checkIndex < 0) || !matching_syms(checker[checkIndex], c)) {
            printf("%c does not have matching opening symbol. Exiting...\n", c);
            exit(1);
         } else {
            checker[checkIndex--] = '\0';
         }
      } else if (is_opening_sym(c)) {
         checker[++checkIndex] = c;
      }

      i++;
   }
}
