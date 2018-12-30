#include <stdio.h>
#define LIMIT 100000

/* removes comments from C programs. assumimg that the C file can be compiled
before removing the comments. */

int read_file(char before[], int lim);
void remove_comments(char before[], char after[]);

int main()
{
  int length;
  char before[LIMIT], after[LIMIT];

  if ((length = read_file(before, LIMIT)) > 0) {
    printf("BEFORE:\n");
    printf("%s\n\n", before);
    printf("AFTER\n");
    remove_comments(before, after);
    printf("%s\n", after);
  } else {
    printf("Error: File was not found.\n");
  }

  return 0;
}

int read_file(char arr[], int lim)
{
  int i, c;
  FILE *file;

  file = fopen("cprogram.c", "r");
  if (file) {
    i = -1;
    while ((c = getc(file)) != EOF && i < lim) {
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
      while (before[i] != '\n')
        ++i;
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
