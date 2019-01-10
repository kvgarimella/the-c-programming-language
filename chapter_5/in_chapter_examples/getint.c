#include <stdio.h>
#include <ctype.h>
#define SIZE 5
#define BUFSIZE 100

int buf[BUFSIZE];
int bufp = 0;

int getch(void);
void ungetch(int);
int getint(int *);


int main()
{
  int n, array[SIZE], i;
  for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++) {}

  for (i = 0; i < SIZE; i++)
  {
    printf("%d\n", array[i]);
  }
}

int getint(int *pn)
{
  int c, sign;

  while (isspace(c = getch())) {}

  if (!isdigit(c) && c != EOF && c != '+' && c != '-')
  {
    ungetch(c);
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-')
  {
    c = getch();
  }
  for (*pn = 0; isdigit(c); c = getch())
  {
    *pn = 10 * *pn + (c - '0');
  }
  *pn *= sign;

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
