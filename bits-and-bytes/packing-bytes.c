#include <stdio.h>

int main() {
  unsigned char b3 = 202;
  unsigned char b2 = 254;
  unsigned char b1 = 186;
  unsigned char b0 = 190;
  int u = b3;
  u = u << 8;
  u = u | b2;
  u = u << 8;
  u = u | b1;
  u = u << 8;
  u = u | b0;
  printf("%x\n", u);
}