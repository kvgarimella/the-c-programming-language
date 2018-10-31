#include <stdio.h>
#include <math.h>

// this is a function prototype
// could have also been: int power(int, int);
int power(int m, int n);

// Testing the power function

int main()
{
  int i;

  for (i = 0; i < 10; i++) {
    printf("%d %d %d\n", i, power(2,i), power(-3,i));
    printf("Internal Pow: %d %f %f\n", i, pow(2,i), pow(-3,i));
  }
  return 0;
}

// base to the power of n
int power(int base, int n) {
  int i, p;

  p = 1;
  for (i = 1; i < n; ++i) {
    p = p * base;
  }
  return p;
}
