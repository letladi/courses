#include <stdio.h>
#include "../util.h"
#include "lines.h"
#include "alloc.h"

// read input lines
int readlines(char *lineptr[], int maxlines)
{
   int len, nlines;
   char *p, line[MAXLEN];
   nlines = 0;

   while ((len = getLine(line, MAXLEN)) > 0)
      if (nlines >= maxlines || (p = alloc(len)) == NULL) return -1;
      else {
         line[len - 1] = '\0'; // delete newline
         strcpy(p, line);
         lineptr[nlines++] = p;
      }

   return nlines;
}

// write output lines
// void writelines(char *lineptr[], int nlines)
// {
//    int i;
//    for (i = 0; i < nlines; i++)
//       printf("%s\n", lineptr[i]);
// }
void writelines(char *lineptr[], int nlines)
{
   while (nlines-- > 0)
      printf("%s\n", *lineptr++);
}

// quick sort v[left]...v[right] into increasing order
void qsort(char *v[], int left, int right)
{
   int i, last;

   void swap(char *v[], int i, int j);

   if (left >= right) // do nothing if array contains fewer than 2 elements
      return;
   swap(v, left, (left + right)/2);
   last = left;

   for (i = left + 1; i <= right; i++)
      if (strcmp(v[i], v[left]) < 0) swap(v, ++last, i);

   swap(v, left, last);
   qsort(v, left, last - 1);
   qsort(v, last + 1, right);
}

// interchange v[i] and v[j]
void swap(char *v[], int i, int j)
{
   char *temp;
   temp = v[i];
   v[i] = v[j];
   v[j] = temp;
}
