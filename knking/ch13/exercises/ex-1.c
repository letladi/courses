/**
 * b) does not work, the format specifies a character, but a string is supplied
 * c) does not work, the format specifies a string, but a character is supplied
 * e) does not work, printf expect its first argument to be a string
 * h) does not work, putchar expects its argument to be a character
 * i) does not work, puts expects its argument to be a string, but a character is supplied
 */
 #include <stdio.h>
 
 int main(void)
 {
   // a) ✔️
   // printf("%c", '\n');
   // b) ✔️
   // printf("%c", "\n");
   // c) ✔️
   // printf("%s", '\n');
   // d) ✔️
   // printf("%s", "\n");
   // e) ✔️
   // printf('\n');
   // f) ✔️
   // printf("\n");
   // g) ✔️
   // putchar('\n');
   // h) ✔️
   // putchar("\n");
   // i) ✔️
   // puts('\n');
   // j) ❌ This actually writes more than one newline character 
   // (the one passed in as an argument) and then a default one the 
   // function will write after writing the passed in string
   // puts("\n");
   // k) ✔️
   // puts("");
   
   return 0;
 }