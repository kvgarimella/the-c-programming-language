#include <stdio.h>

#define IN  1 //inside a word
#define OUT 0 // outside a word

/*
counts the lines, words and characters in an input. similar to command 'wc'
*/
int main()
{
  int c, nl, nw, nc, state;

  state = OUT;

  // assignments associative from left to right so you get
  // nl = (nw = ( nc = 0));
  nl = nw = nc = 0;
  while((c = getchar()) != EOF) {
    // always increment number of chars
    ++nc;

    if (c == '\n') {
      ++nl;
    }
    // && for AND and || for OR!
    if (c == ' ' || c == '\t' || c == '\n') {
      state = OUT;

    }
    else if (state == OUT) {
      state = IN;
      ++nw;
    }

  }
  printf("%d %d %d\n", nl, nw, nc);
}
