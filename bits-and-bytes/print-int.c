#include <stdio.h>

int main() {
  int x = 10;
  int y = 13;

  printf("x = %d\n", x);
  printf("y = %d\n", y);
  printf("size of signed int in bytes is %d.\n", sizeof(x));
  printf("size of signed int in bits is %d.\n", sizeof(x)*8);
  printf("%d + %d = %d.\n", x,y,x+y);
}