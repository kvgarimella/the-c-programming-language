#include <stdio.h>
#include <ctype.h>
#include "../in_chapter_examples/reverse.c"
#define MAX_DIGIT 9
#define LIMIT 1000

// convert int n to a base b character representation in s.

void itob(int, char[], int);

int main()
{
  char s[1000];
  int n = 0;
  int b = 2;
  itob(n, s, b);
  printf("%s\n", s);
  return 0;
}

void itob(int n, char s[], int b)
{
  int i, curr_conversion;
  i = 0;

  do
  {
    curr_conversion = n % b;
    if (curr_conversion <= MAX_DIGIT)
    {
      s[i++] = curr_conversion + '0';
    }
    else
    {
      s[i++] = curr_conversion + 'A' - 10;
    }
    n /= b;
  } while (n > 0);

  s[i] = '\0';
  reverse(s);
}
