#include <stdio.h>

int main() {
  unsigned int x = 0xCAFEBABE;
  int a = x>>29;
  int b = x<<3>>28;
  int c = x<<7>>28;
  int d = x<<11>>29;
  int e = x<<14>>29;
  int f = x<<17>>28;
  int g = x<<21>>28;
  int h = x<<25>>29;
  int i = x<<28>>30;
  int j = x<<30>>30;
  printf("%d %d %d %d %d %d %d %d %d %d\n", a,b,c,d,e,f,g,h,i,j);
}