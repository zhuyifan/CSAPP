#include <stdio.h>

int main() {
  unsigned int a = 17512807u;
  int b = 8;
  unsigned int b1 = ((a>>22)<<22)|(b<<18)|((a<<14)>>14);
  int c = 17;
  unsigned int c1 = ((b1>>15)<<15)|(c<<10)|((b1<<22)>>22);
  printf("%08x\n", c1);
}