#include <stdio.h>

long fib(long);

long fib(long n)
{
  if (n < 0) {
    printf("Error on fib(%ld). You must call fib on a non-negative number.\n", n);
  } else if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {

    long i, fibs[n];
    fibs[0] = 0;
    fibs[1] = 1;

    for (i = 2; i < n + 1; ++i) {
      fibs[i] = fibs[i - 1] + fibs[i - 2];
    }
    return fibs[n];
  }
  return -1;
}


int main(int argc,char* argv[])
{
  printf("%d\n", argc);
  long k;
  long k_th_fib;

  k = 1000;

  k_th_fib = fib(k);
  printf("Fibonnaci Element %ld: %ld\n", k, k_th_fib);
  return 0;
}
