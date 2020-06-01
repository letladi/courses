#pragma once

void reverse(char s[]);
void itoa(int n, char s[]);
int trim(char s[]);
int getLine(char s[], int lim);
int strindex(char s[], char t[]);
int strrindex(char s[], char t[]);
double stof(char s[]);
int strlen(char *s);
void strcpy(char *s, char *t);
int strcmp(char *s, char *t);
#define NUMBER '0'
#define MAXLINE 1000

int getch(void);
void ungetch(int);
int getop(char s[]);
void push(double);
double pop(void);
int stoi(char s[]);

char *month_name(int n);

int to_int(char s[]);
