#include <stdio.h>

int main()
{
  int c;
  // if you use type: int for blanks, newlines, tabs, you will get funky results

  double blanks, tabs, newlines;

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      ++blanks;
    }
    if (c == '\t') {
      ++tabs;
    }
    if (c == '\n') {
      ++newlines;
    }
  }

  printf("Blanks: %.0f\nTabs: %.0f\nNewlines: %0.f\n",blanks, tabs, newlines);
}
