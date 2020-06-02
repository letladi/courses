#pragma once

#include <stdio.h>
#include "../util.h"

#define MAXLINES 5000 // lines to be sorted

char *lineptr[MAXLINES]; // pointers to text lines

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);
void swap(char *v[], int i, int j);

#define MAXLEN 1000 /* max length of any input line */

int getLine(char *, int);
char *alloc(int);
