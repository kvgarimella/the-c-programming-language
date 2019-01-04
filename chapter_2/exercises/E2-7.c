#include <stdio.h>

unsigned invert(unsigned, int, int);

int main()
{
  unsigned x = 1234;
  int p = 1;
  int n = 2;
  unsigned bits = invert(x, p, n);
  printf("%u\n", bits);
  return 0;
}

unsigned invert(unsigned x, int p, int n)
{
  // unsigned bits = x & (~(~0 << n) << (p + 1 - n));
  // return bits;

  // probably could be written better but it works.
  unsigned off;
  off = x & ~(~(~0 << n) << (p + 1 - n));
  unsigned inverted = (~((x >> (p + 1 - n)) & ~(~0 << n)) & ~(~0 << n)) << (p + 1 - n);
  return off + inverted;
}
