#include <stdio.h>

int main() {
  float x = 10.000000;
  float y = 13.000000;

  printf("x = %f\n", x);
  printf("y = %f\n", y);
  printf("size of single float in bytes is %d.\n", sizeof(x));
  printf("size of single float in bits is %d.\n", sizeof(x)*8);
  printf("%f + %f = %f.\n", x,y,x+y);
  printf("%f + %f = %d.\n", x,y,(int)(x+y));
}