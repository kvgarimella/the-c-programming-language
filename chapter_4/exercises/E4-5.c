#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100
#define MAXVAL 100
#define BUFSIZE 100
#define NUMBER '0'
#define MATH 'm'

int getch(void);
void ungetch(int);
int getop(char []);
void push(double);
double pop(void);
double peek(void);
void swap(void);
void dup(void);
void clear(void);


int main()
{
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF)
  {
    switch (type)
    {
      case NUMBER:
        push(atof(s));
        break;
      case MATH:
        if (strcmp(s, "sin") == 0)
        {
          push(sin(pop()));
        }
        else if (strcmp(s, "pow") == 0)
        {
          op2 = pop();
          push(pow(pop(), op2));
        } else if (strcmp(s, "exp") == 0)
        {
          push(exp(pop()));
        }
        else
        {
          printf("error: unknown command.\n");
        }
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2 = pop();
        if (op2 != 0.0)
        {
          push(pop() / op2);
        }
        else
        {
          printf("error: divide by zero.\n");
        }
        break;
      case '%':
        op2 = pop();
        if (op2 != 0.0)
        {
          push((int) pop() % (int) op2);
        }
        else
        {
          printf("error: modulo by zero.\n");
        }
        break;
      case 'p':
        printf("\tTop Element: %.g\n", peek());
        break;
      case 'd':
        dup();
        break;
      case 's':
        swap();
        break;
      case 'c':
        clear();
        break;
      case '\n':
        printf("\t%.8g\n",pop());
        break;
      default:
        printf("error: unknown command.\n");
        break;
    }
  }
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
    push(peek());
  }
  else
  {
    printf("error. stack either empty or full.\n");
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

  i = 0;
  if (islower(c))
  {
    while (islower(s[++i] = c = getch())){}
    s[i] = '\0';
    if (strlen(s) > 1)
    {
      return MATH;
    }
    else
    {
      return c;
    }
  }
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
