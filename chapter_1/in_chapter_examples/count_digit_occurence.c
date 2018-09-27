#include <stdio.h>

int main() {

  int c, i, nwhite, nother;
  int ndigit[10];    // note that you have to declare size of array

  nwhite = nother = 0;
  for (i = 0; i < 10; i = i + 1) {
    ndigit[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c >= '0' && c<= '9') {
      ++ndigit[c-'0'];
    } else if (c == ' ' || c == '\n' || c == '\t') {
      ++nwhite;
    } else {
      ++nother;
    }
  }

  printf("digits =");
  for (i = 0; i < 10; ++i) {
    printf(" %d", ndigit[i]);
  }
  printf(", white space = %d, other = %d\n", nwhite, nother);


}
