#include <stdio.h>

/*
We will define some symbolic constants instead of defining them
within the function
*/

/*
Things to note: no semi-colons (maybe because the line starts with a hash)
the type is not declared so it has to be inferred at some point.
Also, the variable names are in upper case as a way to distinguish from
variables.

#define NAME replacement(can be any sequence of chars)
*/

#define LOWER 0
#define UPPER 300
#define STEP 20

int main()
{
  int fahr;
  for (fahr = LOWER; fahr <= UPPER; fahr += STEP) {
    printf("%d %6.1f\n", fahr, (5./9.)*(fahr - 32.));
  }
}
