#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

double atof(char s[]);

int main()
{
  char s[] = "1.2e2\0";
  double conversion = atof(s);
  printf("%f\n", conversion);
  return 0;
}

double atof(char s[])
{
  double val, power;
  int i, sign, signed_exp, exp;

  for (i = 0; isspace(s[i]); i++) {}

  sign = (s[i] == '-') ? -1 : 1;

  if (s[i] == '+' || s[i] == '-')
  {
    i++;
  }

  for (val = 0.0; isdigit(s[i]); i++)
  {
    val = 10.0 * val + (s[i] - '0');
  }

  if (s[i] == '.')
  {
    i++;
  }

  for (power = 1.0; isdigit(s[i]); i++)
  {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }

  if (tolower(s[i]) == 'e')
  {

    i++;
    signed_exp = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
    {
      i++;
    }

    for(exp = 0; isdigit(s[i]); i++)
    {
      exp = 10 * exp + (s[i] - '0');
    }

  }

  return sign * (val / power * pow(10, exp));
}
