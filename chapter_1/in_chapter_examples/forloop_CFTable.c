#include <stdio.h>

int main()
{
  int fahr;


// Note that fahr += 20 is the same as fahr = fahr + 20;
  for (fahr = 0; fahr <= 300; fahr += 20) {
    printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr - 32.));
  }
}
