#include <stdio.h>

#define MAXLINE 1000
#define MINIMUM 80

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


  while ((len = getLine(line, MAXLINE)) > 0) {
    if (len > MINIMUM) {
      copy(longest, line);
      printf("Length of this line: %d\n", len);
      printf("%s", longest);
    }
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
