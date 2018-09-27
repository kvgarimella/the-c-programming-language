#include <stdio.h>

/*
After running this program several times, I see that the array
is initialized with indeterminate values.

What is in my array: 0, 0, 0, 0, 0, 0, 0, 0, -390707112, 32766
*/

int main ()
{
  int size;
  size = 2;
  int ndigit[size];


  int i;
  printf("What is in my array: ");
  for (i = 0; i < size - 1; ++i) {
    printf("%d, ", ndigit[i]);
  }
  printf("%d\n", ndigit[size - 1]);
}
