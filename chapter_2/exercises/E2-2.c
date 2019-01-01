#include <stdio.h>

// write a loop equivalent of the for loop.

int main()
{
  int c, i;
  int lim = 100;
  char s[lim];


  // the loop
  for(i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
  {
    s[i] = c;
  }


  // first attempt:
  i = 0;
  while (i < lim - 1)
  {
    if ((c = getchar()) != '\n')
    {
      if (c != EOF)
      {
        s[i] = c;
      }
      else
      {
        i = lim;
      }
    }
    else
    {
      i = lim;
    }
    ++i;
  }

  // second attempt:
  i = 0;
  while (i < lim - 1)
  {
    c = getchar();
    if (c == EOF)
    {
      break;
    }
    else if (c == '\n')
    {
      break;
    }
    s[i++] = c;
  }

}
