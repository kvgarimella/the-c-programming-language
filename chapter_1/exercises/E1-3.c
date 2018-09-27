#include <stdio.h>

/*
Multi-Line comment.
Cool
*/

/*
This computer program will print a table of Fahrenheit-Celcius values!
*/

// we need a main method. Oh look, two slashes is a single line comment.
int main()
{
  float fahr, celcius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step  = 20;

  fahr = lower;
  printf("Fahrenheit Celcius\n");
  while (fahr <= upper) {
    celcius = 5.0 * (fahr - 32.) / 9.0;
    printf("%3.0f\t\t%6.2f\n", fahr, celcius);
    fahr = fahr + step;
  }
}
