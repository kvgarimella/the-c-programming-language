#include <stdio.h>

#define MAXLINE 1000

// function prototypes..
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
    printf("%s", longest);
  }
  return 0;
}



int getLine(char s[], int lim)
{
  int c, i;
  for (i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; ++i)
  {
    s[i] = c; // filling an array of characters with current line.
  }
  if (c == '\n')
  {
    s[i] = c;
    ++i;
  }
  s[i] = '\0'; // NUL byte. You can find length of string by searching for
               // first occurence of '\0'
  return i; // returns length of line.

}

void copy(char to[], char from[])
{
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}
