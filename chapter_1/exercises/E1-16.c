#include <stdio.h>

#define MAXLINE 1000

// had to use getLine() instead of getline() because stdio.h
// already as a getline() function.



int getLine(char s[], int lim);
void copy(char to[], char from[]);

int main()
{
  int len;
  int max;

  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  while ((len = getLine(line, MAXLINE)) > 0) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }
  if (max > 0) {
    printf("Length of Longest Line: %d\n", max);
    printf("%s", longest);
  }


  return 0;
}

int getLine(char s[], int lim)
{
  int c,i;
  i = -1;

  while ((c = getchar()) != EOF && c != '\n') {
    ++i;
    if (i < lim - 1) {
      s[i] = c;
    }
  }

  if (c == '\n' && i < lim - 1) {
    s[i] = c;
    ++i;
  }
  if (i < lim - 1) {
    s[i] = '\0';
  }
  return i;
}


void copy(char to[], char from[]) {
  int i;

  i = 0;
  while((to[i] = from[i]) != '\0') {
    ++i;
  }
}
