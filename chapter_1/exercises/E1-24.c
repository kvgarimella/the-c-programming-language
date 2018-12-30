#include <stdio.h>
#define LIMIT 100000

/*
Write a program to check a C program for rudimentary syntax errors like
 - unbalanced parentheses
 - unbalanced brackets
 - unbalanced braces

*/

/*
steps:
first read in file.
then remove all comments (just use E1-23.c)
then figure out a method for checking unbalanced parentheses, brackets, braces
it would be nice to use a stack.  just push each of these onto a stack. then,
if the opposite of whatever opening bracket/brace is used, pop from the stack.
check the length of the stack at the end. if it zero, we are good.
{[[]]}

*/


int read_file(char before[], int lim);
void remove_comments(char before[], char after[]);
int check_syntax(char after[]);
int length(char str[]);

int main()
{
  int length;
  char before[LIMIT], after[LIMIT];
  int length_of_stack;
  if ((length = read_file(before, LIMIT)) > 0)
  {
    remove_comments(before, after);
    printf("%s\n", after);
    if ((length_of_stack = check_syntax(after)) > 0)
    {
      printf("There is an imbalance of parentheses, brackets, and braces in this program.\n");
    }
    else
    {
      printf("This program does not contain any rudimentary syntax errors!\n");
    }

  }
  else
  {
    printf("Error. File not found.\n");
  }
}

int read_file(char arr[], int lim)
{
  int i, c;
  FILE *file;

  file = fopen("/Users/karthik/Desktop/first.c", "r");
  if (file)
  {
    i = -1;
    while ((c = getc(file)) != EOF && i < lim)
    {
      ++i;
      arr[i] = c;
    }
    arr[++i] = '\0';
    return i;
  }
  return 0;
}

void remove_comments(char before[], char after[])
{
  int c, i, j;

  i = 0;
  j = 0;


  while ((c = before[i++]) != '\0')
  {
    // handles "//" or "/* ... */" within strings.
    if (c == '\"')
    {
      after[j++] = c;
      while ((c = before[i++]) != '\"')
      {
        after[j++] = c;
      }
    }

    // skips single and multi-line comments
    if (c == '/' && before[i] == '/')
    {
      while (before[i++] != '\n')
        {}
    }
    else if (c == '/' && before[i] == '*')
    {
      while (!(before[i++] == '*' && before[i++] == '/'))
        {}
    }
    else
    {
      after[j++] = c;
    }
  }
}

int check_syntax(char after[])
{
  char syntax[LIMIT];
  int c, i, j;

  i = 0;
  j = 0;

  while ((c = after[i++]) != '\0')
  {
    // ignore braces, etc. in quotes
    if (c == '\"')
    {
      while ((c = after[i++]) != '\"')
      {}
    }

    // ignore braces, etc. in quotes
    if (c == '\'')
    {
      while ((c = after[i++]) != '\'')
      {}
    }

    if (c == '{' || c == '[' || c == '(')
    {
      syntax[j++] = c;
    }

    else if (c == '}')
    {

      if (syntax[j - 1] == '{')
      {
        j--;
      }
    }
    else if (c == ']')
    {
      if (syntax[j - 1] == '[')
      {
        j--;
      }
    }
    else if (c == ')')
    {
      if (syntax[j - 1] == '(')
      {
        j--;
      }
    }
  }
  syntax[j] = '\0';
  return length(syntax);


}

int length(char str[])
{
  int i;
  i = 0;
  while (str[i] != '\0')
  {
    ++i;
  }
  return i;
}
