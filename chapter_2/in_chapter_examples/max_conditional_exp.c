#include <stdio.h>

int max(int, int);

int main()
{
  int a = 6;
  int b = 7;
  printf("max: %d\n",  max(a,b));
}

int max(int a, int b)
{
  // (exp1 ? exp2 : exp3) ->
  // if (exp1)
  // {
  //   return exp2;
  // }
  // return exp3;
  return (a > b) ? a : b;
}
