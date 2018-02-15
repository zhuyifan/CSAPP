#include <stdio.h>

int main() {
  char c = 'C';
  char a = 65;
  char b = 'B';
  char e = 'E';
  char f = 'F';

  printf("c = %c\n", c);
  printf("a = %c\n", a);
  printf("%c%c%c%c%c%c%c%c\n", c,a,f,e,b,a,b,e);
  printf("number of bytes: %d.\n", sizeof("CAFEBABE"));
}