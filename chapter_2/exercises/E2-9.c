#include <stdio.h>

int bitcount(unsigned);

int main()
{
  unsigned x = 1444;
  int num_one_bits = bitcount(x);
  printf("%d\n", num_one_bits);
  return 0;
}

int bitcount(unsigned x)
{
  int b;

  while ((x &= (x - 1)) != 0)
  {
    ++b;
  }
  return ++b;
}
