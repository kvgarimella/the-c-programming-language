#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100
#define MAXVAL 100
#define LINELIM 100
#define NUMBER '0'
#define MATH 'm'


int getop(char []);
void push(double);
double pop(void);
double peek(void);
void swap(void);
void dup(void);
void clear(void);
int get_line(char line[], int max);




int main()
{
  int type;
  double op2;
  char s[MAXOP];
  double var[26];
  int line_len;
  int curr_var = 'A';
  int i, c;
  char curr_op[MAXOP];
  int j;

  while ((line_len = get_line(s, LINELIM)) > 0)
  {
    for (i = 0; isspace(s[i]); i++) {} // handle leading whitespace.
    while (s[i] != '\0' || s[i] == '\n')
    {
      curr_op[0] = c = s[i];
      j = 0;
      if (islower(c))
      {
        c = s[++i];
        if (islower(c))
        {
          curr_op[++j] = c;
          while(islower(curr_op[++j] = c = s[++i])) {}
          curr_op[j] = '\0';
        }
        else
        {
          curr_op[1] = '\0';
        }
        if (strlen(curr_op) > 1)
        {
          type = MATH;
        }
        else
        {
          type = curr_op[0];
        }
      }
      else if (!isdigit(c) && c != '.' && c != '-')
      {
        type = c;
      }
      else
      {
        j = 0;
        if (c == '-')
        {
          curr_op[++j] = c = s[++i];
        }
        if (isdigit(c))
        {
          while (isdigit(curr_op[++j] = c = s[++i])) {}
        }
        if (c == '.')
        {
          while (isdigit(curr_op[++j] = c = s[++i])) {}
        }
        curr_op[j] = '\0';
        type = NUMBER;
      }

      switch (type)
      {
        case NUMBER:
          push(atof(curr_op));
          break;
        case MATH:
          if (strcmp(curr_op, "sin") == 0)
          {
            push(sin(pop()));
          }
          else if (strcmp(curr_op, "pow") == 0)
          {
            op2 = pop();
            push(pow(pop(), op2));
          } else if (strcmp(curr_op, "exp") == 0)
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
        case 'v':
          op2 = pop();
          var[curr_var - 'A'] = op2;
          curr_var++;
          break;
        case '\n':
          printf("\t%.8g\n",pop());
          break;
        default:
          if (isupper(type))
          {
            push(var[type - 'A']);
          }
          else
          {
            printf("error: unknown command.\n");
          }

          break;
      }
      ++i;
    }
  }
  return 0;
}

double val[MAXVAL];
/*  ..a char array can't hold a negative value.
Change the buffer type to int and the problem is solved.
Got help from stack overflow on this one. */

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

int get_line(char s[], int lim)
{
  int c, i;

  i = 0;

  while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
  {
    s[i++] = c;
  }
  if (c == '\n')
  {
    s[i++] = c;
  }
  s[i] = '\0';
  return i;
}
