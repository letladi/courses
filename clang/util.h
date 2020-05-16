void reverse(char s[]);
void itoa(int n, char s[]);
int trim(char s[]);
int getLine(char s[], int lim);
int strindex(char s[], char t[]);
int strrindex(char s[], char t[]);
double stof(char s[]);

#define NUMBER '0'
#define MAXLINE 1000

int getch(void);
void ungetch(int);
int getop(char s[]);
void push(double);
double pop(void);
int stoi(char s[]);
