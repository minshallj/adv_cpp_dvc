// jacob minshall
// struct.cpp

// soccer players, and their information
// takes user input on 10 soccer players, and then searches for another
// user input soccer player

#include <iostream>
#include <vector.h>

using namespace std;

void fill_player(vector<Soccer_player> &guy, int n = 1);

typedef struct
{
  string l_name;
  string f_name;
  int birth_month;
  int birth_day;
  int birth_year;
}Soccer_player;

int main()
{
  const int size = 6;

  vector<Soccen_player> team;

  for(int i = 0; i < size; i++)
    fill_player(team);

  
  return 0;
}

void fill_player(vector<Soccer_player> &guy, int n)
{
  cout << "Please enter last name, first name, birth month(1-12), birth date(1-31) ";
  cout << "and birth year seperated by spaces: " << endl;

  for(int i = 0; i < n; i++) {
    cout << "Person " << i + 1 << ": ";
    guy.push_back();
    cin >> guy[i].l_name >> guy[i].f_name >> guy[i].birth_month >> guy[i].birth_day
        >> guy[i].birth_year;
  }

}
