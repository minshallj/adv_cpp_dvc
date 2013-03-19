// time.c
// jacob minshall

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
  int h1, m1, h2, m2;
  char flushy;

  cout << "Please enter time #1 in clock format: ";
  scanf("%d%c%d", &h1, &flushy, &m1);

  cout << "Please enter time #2 in clock format: ";
  scanf("%d%c%d", &h2, &flushy, &m2);

  //minutes should be abs()
  printf("The difference is %d:%02d.\n", h1 - h2, abs(m1 - m2));

  return 0;
}
