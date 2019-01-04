#include <stdio.h>
#define UNSIGNED_MAX_BITS 32

unsigned rightrot(unsigned, int);

int main()
{
  unsigned x = 1229;
  int n = 4;
  printf("%u\n", x);
  unsigned rotated_val = rightrot(x, n);
  printf("rotated: %u\n", rotated_val);
  return 0;
}

unsigned rightrot(unsigned x, int n)
{
  unsigned bits_to_rot = (~(~0 << n) & x) << (UNSIGNED_MAX_BITS - n);
  return (bits_to_rot + (x >> n));
  return x;
}
