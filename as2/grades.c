// grades.c
// jacob minshall

//#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//using namespace std;

void get_grades(int *a, int *b, int *c, int *d, int *f, const char * course);
void show_totals(int a, int b, int c, int d, int f);


int main()
{
  int a = 0, b = 0, c = 0, d = 0, f = 0;

  get_grades(&a, &b, &c, &d, &f, "ECS 10");
  get_grades(&a, &b, &c, &d, &f, "ECS 20");
  get_grades(&a, &b, &c, &d, &f, "ECS 30");
  get_grades(&a, &b, &c, &d, &f, "ECS 40");

  show_totals(a, b, c, d, f);

  return 0;
}

void get_grades(int *a, int *b, int *c, int *d, int *f, const char * course)
{
  int aa, bb, cc, dd, ff;
  printf("Please enter the grades for %s in order As Bs Cs Ds Fs: ", course);

//  cin >> aa >> bb >> cc >> dd >> ff;
  scanf("%d%d%d%d%d", &aa, &bb, &cc, &dd, &ff);
  *a += aa;
  *b += bb;
  *c += cc;
  *d += dd;
  *f += ff;
}

void show_totals(int a, int b, int c, int d, int f)
{
  int n = a + b + c + d + f;

  printf("The percentages were A: %d%%, B: %d%%, C: %d%%, D: %d%%, F: %d%%.\n",
         a*100/n, b*100/n, c*100/n, d*100/n, f*100/n);
}
