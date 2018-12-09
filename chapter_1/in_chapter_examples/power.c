#include <stdio.h>
#include <math.h>

// this is a function prototype
// could have also been: int power(int, int);
int power(int m, int n);

// Testing the power function

int main()
{
  int i;
  int k;

  // calling functions only reference parameters
  // except for arrays; arrays are passed in as an address
  k = 10;
  printf("k = %d\n", k);
  printf("%d\n", power(2,k));
  printf("Notice that k will not change even after power is called\n");
  // so a reference is being passed
  printf("k = %d\n", k);

  // for (i = 0; i < 10; i++) {
  //   printf("%d %d %d\n", i, power(2,i), power(-3,i));
  //   printf("Internal Pow: %d %f %f\n", i, pow(2,i), pow(-3,i));
  // }
  return 0;
}

// base to the power of n
int power(int base, int n) {
  int p;

  for (p = 1; n > 0; --n) {
    p = p * base;
  }
  return p;
}
