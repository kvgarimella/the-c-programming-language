#include <stdio.h>


// this program introduces the concept of post and pre-fix operators
// realize that ++value does not equal value++; more on this later.
// in this case: we are prefixing the long nc: ++nc;

int main()
{

  // version 1: uses a long and a while loop
  // long nc;
  // nc = 0;
  //
  // while (getchar() != EOF) {
  //   ++nc;
  // }
  //
  // printf("%ld\n", nc);

  // version 2: uses a for loop and a double
  // %0.f supresses printing decimal point
  // instead of "{}" after the for loop, I could have used a null statement: ";"
  double nc;

  for (nc = 0; getchar() != EOF; ++nc) {}

  printf("%0.f\n", nc);
}
