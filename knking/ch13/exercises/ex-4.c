#include <stdio.h>
#include <string.h>

// int read_line(char str[], int n)
// {
//    int ch, i = 0;
//    // a)
//    // this will fail codition, but is also incorrect, because the first
//    // non-space character will be discarded in the next loop.
//    // This function is thus not correct
//    while (isspace(ch = getchar())) 
//       ;

//    while (!isspace(ch = getchar()) && (ch != '\n') && (i < n - 2) && ch != EOF) {
//       if (i < n) str[i++] = ch;
//    }
//    if (ch == '\n') str[i++] = '\n';
//    str[i] = '\0';
//    return i;
// }
// ❌


// a)
// int read_line(char str[], int n)
// {
//    int ch, i = 0;
//    while ((ch = getchar()) != '\n')
//       if (i == 0 && isspace(ch)) 
//          ; /* ignore */
//       else if (i < n)
//          str[i++] = ch;
//    str[i] = '\0';
//    return i;
// }

// b)
// int read_line(char str[], int n)
// {
//    int ch, i = 0;
//    while (!isspace(ch = getchar()))
//       if (i < n)
//          str[i++] = ch;
//    str[i] = '\0';
//    return i;
// }

// c)
// int read_line(char str[], int n)
// {
//    int ch, i = 0;
//    do {
//       ch = getchar();
//       if (i < n)
//          str[i++] = ch;
//    } while (ch != '\n');
//    str[i] = '\0';
//    return i;
// }

// d)
// int read_line(char str[], int n)
// {
//    int ch, i;
//    for (i = 0; i < n; i++) {
//       ch = getchar();
//       if (ch == '\n')
//          break;
//       str[i] = ch;
//    }
//    str[i] = '\0';
//    return i;
// }