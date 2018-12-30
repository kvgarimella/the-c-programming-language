#include <stdio.h>

#define N 10
#define MAXLINE 1000


int get_line(char s[], int lim);
void fold_line(char s[], int lim);

int main()
{
  char line[MAXLINE];
  int length;

  while((length = get_line(line, MAXLINE)) > 0)
  {
    fold_line(line, N);
  }


  printf("Hey :)\n");
}

int get_line(char s[], int lim)
{
  int c, i;

  for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
  {
    s[i] = c;
  }
  if (c == '\n')
  {
    s[i++] = '\n';
  }
  s[i] = '\0';
  return i;
}

void fold_line(char s[], int lim)
{
  int i, c, curr_column;

  i = 0;
  c = 0;
  curr_column = 0;

  while ((c = s[i]) != '\0')
  {
    while (curr_column <= lim)
    {
      if (curr_column == 0)
      {
        while (c == ' ' || c == '\t')
        {
          c = s[++i];
        }
      }
      putchar(c);
      c = s[++i];
      ++curr_column;
    }
    putchar('\n');
    curr_column = 0;
  }
}
