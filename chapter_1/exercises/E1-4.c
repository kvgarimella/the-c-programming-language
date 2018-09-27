#include <stdio.h>

/*
This program will print the corresponding Fahrenheit for several Celcius values


*/

int main()
{
  float celcius, fahr;
  int lower, upper, step;
  lower = 0;
  upper = 100;
  step = 5;

  celcius = lower;
  printf("Celcius     Fahrenheit\n");
  while (celcius <= upper) {
    fahr = (9./5.) * celcius + 32.;
    printf("%3.2f\t\t%3.2f\n", celcius, fahr);
    celcius = celcius + step;
  }

}
