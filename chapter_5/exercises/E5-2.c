#include <stdio.h>
#include <ctype.h>
#define SIZE 5
#define BUFSIZE 100

int buf[BUFSIZE];
int bufp = 0;

int getch(void);
void ungetch(int);
int getfloat(float *);


int main()
{
  int n, i;
  float array[SIZE];

  for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++) {}

  for (i = 0; i < SIZE; i++)
  {
    printf("%f\n", array[i]);
  }
}

int getfloat(float *pn)
{
  int c, sign;

  float power;

  while (isspace(c = getch())) {}

  if (!isdigit(c) && c != EOF && c != '+' && c != '-')
  {
    ungetch(c);
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-')
  {
    while (isblank(c = getch())) {}
  }

  for (*pn = 0; isdigit(c); c = getch())
  {
    *pn = 10 * *pn + (c - '0');
  }

  if (c == '.')
  {
    while (isblank(c = getch())) {}
  }

  for (power = 1.0; isdigit(c); c = getch())
  {
    *pn = 10 * *pn + (c - '0');
    power *= 10;
  }

  *pn = *pn * sign / power;

  if (c != EOF)
  {
    ungetch(c);
  }
  return c;
}

int getch(void)
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
  if (bufp >= BUFSIZE)
  {
    printf("ungetch: too many characters\n");
  }
  else
  {
    buf[bufp++] = c;
  }
}
