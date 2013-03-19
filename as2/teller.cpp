// teller.cpp
// jacob minshall

#include <iostream>
using namespace std;

//function prototype
void ask(int &teller, int tel_num, int year);
void display(int t1, int t2);

int main()
{
  int t1 = 0, t2 = 0;

  ask(t1, 1, 1);
  ask(t1, 1, 2);
  ask(t1, 1, 3);
  ask(t2, 2, 1);
  ask(t2, 2, 2);
  ask(t2, 2, 3);

  display(t1, t2);
}

//takes a reference to inc the actual value and ints to print out appropriate mess
void ask(int &teller, int tel_num, int year)
{
  int temp;

  cout << "Enter the number for teller " << tel_num << " for year " << year << endl;
  cin >> temp;

  teller += temp;
}

void display(int t1, int t2)
{
  cout << "The total days missed were: " << t1 + t2 << endl;
}
