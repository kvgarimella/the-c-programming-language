#include <stdio.h>


int convert_f_to_c(int);
int convert_c_to_f(int);

int convert_c_to_f(int celcius) {
  return (9./5.) * celcius + 32.;
}

int convert_f_to_c(int fahrenheit) {
  return (5./9.) * (fahrenheit - 32.);
}

int main()
{
  float celcius, fahr;
  int lower, upper, step;
  lower = -100;
  upper = 100;
  step = 5;

  celcius = lower;
  printf("Celcius     Fahrenheit\n");
  while (celcius <= upper) {
    fahr = convert_c_to_f(celcius);
    printf("%3.2f\t\t%3.2f\n", celcius, fahr);
    celcius = celcius + step;
  }
}
