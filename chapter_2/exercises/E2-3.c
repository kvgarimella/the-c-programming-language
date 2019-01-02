#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define LIMIT 1000
#define HEXBASE 16
#define MIN_LEN 3
#define A_VAL 10

int htoi(char s[], int length, int leading_str);


int main()
{
  int c, integer_value;
  char hex_string[LIMIT];


  printf("Input a hexadecimal number. Then hit enter.\n");

  int i = 0;
  int leading_str = 0;
  while ((c = getchar()) != '\n' && i < LIMIT - 2)
  {
    if (!isdigit(c))
    {
      if (!(c >= 'A' && c <= 'F') && !(c >= 'a' && c <= 'f'))
      {
        if (c != 'x' && c != 'X')
        {
          printf("Error: Each character be a hexidecimal number.\n");
          return 0;
        }
      }
    }
    if (c == 'x' || c == 'X')
    {
      leading_str = 1;
    }
    hex_string[i++] = c;

  }
  hex_string[i] = '\0';

  integer_value = htoi(hex_string, i, leading_str);
  if (!(integer_value == -1))
  {
    printf("Integer Equivalent: %d\n", integer_value);
  }

  return 0;
}

int htoi(char s[], int length, int leading_str)
{
  int curr_index, end_index, integer_value, i , c;

  if (leading_str)
  {
    end_index = 2;
    if (length < MIN_LEN)
    {
      printf("Error: Optional 0X (0x) used without further hexidecimal characters.\n");
      return -1;
    }
  }
  else
  {
    end_index = 0;
  }

  curr_index = length - 1;
  i = 0;
  integer_value = 0;
  while (curr_index >= end_index) {

    c = s[curr_index];
    if (isdigit(c))
    {
      integer_value += pow(HEXBASE, i) * (c - '0');
    }
    else
    {
      integer_value += pow(HEXBASE, i) * (tolower(c) - 'a' + A_VAL);
    }

    i++;
    curr_index--;
  }

  return integer_value;
}
