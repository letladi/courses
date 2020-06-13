lo#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAXLINES 5000 // max #lines to be sorted
char *lineptr[MAXLINES]; // pointers to text lines

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void sort(void *lineptr[], int left, int right, int (*comp)(void *, void *), bool order);
int numcmp(char *, char *);
int strcmpi(char *, char *);

// sort input lines
main(int argc, char *argv[])
{
   int nlines; // number of input lines read
   int numeric = 0; // 1 if numeric sort
   bool desc = false;
   bool fold = false;

   if (argc > 1) {
      while ((++argv)[0]) {
         if (*argv[0] == '-') {
            while (*++argv[0]) {
               char c = *argv[0];
               switch(c) {
                  case 'n': numeric = 1; break;
                  case 'r': desc = true; break;
                  case 'f': fold = true; break;
                  default:
                     printf("Invalid options.\nValid Usage: sort [-n] [-r]");
                     break;
               }
            }
         }
      }
   }

   if (argc > 1 && strcmp(argv[1], "-n") == 0) numeric = 1;
   if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
      sort((void **) lineptr, 0, nlines - 1, (int (*)(void*, void*))(numeric ? numcmp : (fold ? strcmpi : strcmp)), desc);
      printf("\n");
      writelines(lineptr, nlines);
      return 0;
   } else {
      printf("input too big to sort\n");
      return 1;
   }
}

// sort v[left]...v[right] into increasing order
void sort(void *v[], int left, int right, int (*comp)(void *, void *), bool desc)
{
   int i, last;
   if (left >= right) return;
   swap(v, left, (left + right) / 2);
   last = left;
   for (i = left + 1; i <= right; i++) {
      if (desc) {
         if ((*comp)(v[i], v[left]) > 0)
            swap(v, ++last, i);
      } else {
         if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
      }
   }


   swap(v, left, last);
   sort(v, left, last - 1, comp, desc);
   sort(v, last + 1, right, comp, desc);
}

#include <stdlib.h>

// compare s1 and s2 numerically
int numcmp(char *s1, char *s2)
{
   double v1, v2;
   v1 = atof(s1);
   v2 = atof(s2);

   if (v1 < v2) return -1;
   else if (v1 > v2) return 1;
   else return 0;
}

#include <ctype.h> // for `tolower`

int strcmpi(char *s, char *t)
{
   char c1, c2;
   while (*s && *t) {
      c1 = tolower(*s);
      c2 = tolower(*t);
      if (c1 < c2) return -1;
      else if (c1 > c2) return 1;
      ++s;
      ++t;
   }

   if (*s && !*t) return 1;
   else if (!*s && *t) return -1;
   else return 0;
}
