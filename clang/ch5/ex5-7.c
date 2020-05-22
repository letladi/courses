#include <stdio.h>
#include "../util.h"

#define MAXLINES 5000 // lines to be sorted

char *lineptr[MAXLINES]; // pointers to text lines

int readlines(char *lineptr[], char all_lines[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

// sort input lines
int main()
{
   int nlines; // number of input lines read
   char all_lines[MAXLINES];

   if ((nlines = readlines(lineptr, all_lines, MAXLINES)) >= 0) {
      qsort(lineptr, 0, nlines - 1);
      writelines(lineptr, nlines);
      return 0;
   } else {
      printf("error: input too big to sort\n");
      return 1;
   }
}

#define MAXLEN 1000 /* max length of any input line */

int getLine(char *, int);
char *alloc(int);

// read input lines
int readlines(char *lineptr[], char cont[], int maxlines)
{
   int len, nlines;
   char *p = cont, line[MAXLEN];
   nlines = 0;

   while ((len = getLine(line, MAXLEN)) > 0)
      if (nlines >= maxlines) return -1;
      else {
         line[len - 1] = '\0'; // delete newline
         lineptr[nlines++] = p;
         strcpy(p, line);
         p += len;
      }

   return nlines;
}
// the code is faster because we are not calling the alloc function in each while
// loop iteration


void writelines(char *lineptr[], int nlines)
{
   printf("\n");
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
