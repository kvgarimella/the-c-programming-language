#include <stdio.h>

#define MAXLINE 1000

// function prototypes..
int getLine(char s[], int lim);
int copy(char to[], char from[], int length);


int main()
{
  int len;
  int max;
  int curr_len;
  char line[MAXLINE];
  char longest[MAXLINE];

  while ((len = getLine(line, MAXLINE)) >= 0) {
      if (len > 0) {
        curr_len = copy(longest, line, len);
        printf("Current Line Length: %d\n", curr_len);
        printf("%s\n", longest);
      }
      else{
        printf("Line was empty.\n");
      }

  }
  return 0;
}



int getLine(char s[], int lim)
{
  int c, i, is_blank;
  is_blank = 1;

  for (i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; ++i)
  {
    if (c != ' ' && c != '\t') {
      is_blank = 0;
    }
    s[i] = c; // filling an array of characters with current line.
  }
  if (is_blank == 1) {
    return 0;
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

int copy(char to[], char from[], int length)
{
  char curr_char;
  int last_char_index, i;

  for(i = 0; i < length; ++i) {
    if (from[i] != '\0' && from[i] != '\t' && from[i] != ' ' && from[i] != '\n') {
      last_char_index = i;
    }
  }

  for(i = 0; i <= last_char_index; ++i) {
    to[i] = from[i];
  }
  to[i] = '\0';
  return i;

}
