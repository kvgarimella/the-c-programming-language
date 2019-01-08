#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP 100
#define MAXVAL 100
#define BUFSIZE 100
#define NUMBER '0'

int getch(void);
void ungetch(int);
int getop(char []);
void push(double);
double pop(void);
double peek(void);
void swap(void);
void dup(void);


int main()
{
  push(32.0);
  push(-12.0);
  dup();
  printf("%f\n", peek());
  push(-500.0);
  swap();
  printf("%f\n", peek());
  return 0;
}

double val[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;
int sp = 0;

void push(double f)
{
  if (sp < MAXVAL)
  {
    val[sp++] = f;
  }
  else
  {
    printf("error: stack full, can't push %g\n", f);
  }
}

double pop(void)
{
  if (sp > 0)
  {
    return val[--sp];
  }
  else
  {
    printf("error: stack empty.\n");
    return 0.0;
  }
}

double peek(void)
{
  if (sp > 0)
  {
    return val[sp - 1];
  }
  else
  {
    printf("error: stack empty. cannot peek.\n");
  }
  return 0.0;
}

void dup(void)
{

  if (sp > 0 && sp < MAXVAL)
  {
    double top_elem = peek();
    push(top_elem);
  }
}

void swap(void)
{
  if (sp > 1)
  {
    double fst = pop();
    double snd = pop();
    push(fst);
    push(snd);
  }
  else
  {
    printf("error. not enough elements on stack.\n");
  }
}

void clear(void)
{
  sp = 0;
}

int getop(char s[])
{
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t') {}

  s[1] = '\0';
  if (!isdigit(c) && c != '.' && c != '-')
  {
    return c;
  }
  i = 0;
  if (c == '-')
  {
    s[++i] = c = getch();
  }
  if (isdigit(c))
  {
    while (isdigit(s[++i] = c = getch())) {}
  }
  if (c == '.')
  {
    while (isdigit(s[++i] = c = getch())) {}
  }
  s[i] = '\0';
  if (c != EOF)
  {
    ungetch(c);
  }
  return NUMBER;
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
