// jacob minshall
// struct.cpp

// soccer players, and their information
// takes user input on 10 soccer players, and then searches for another
// user input soccer player

#include <iostream>
#include <vector.h>

using namespace std;

//function prototypes
void fill_player(vector<Soccer_player> &guy, int n = 1);
void switch(vector<Soccer_player> &team);
void display(vector<Soccer_player> const &team);
void display_sorted(vector<Soccer_player> team);
int soc_cmp(const Soccer_player a, const Soccer_player b);
int soc_cmp_v(const void * a, const void * b);
void display_guy(const Soccer_player &guy);

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
  const int size = 10;

  vector<Soccen_player> team(size);

  fill_player(team, size);
  
  while(big_switch(team))
    ;
  
  return 0;
}

void fill_player(vector<Soccer_player> &guy, int n)
{
  cout << "Please enter last name, first name, birth month(1-12), birth date(1-31) ";
  cout << "and birth year seperated by spaces: " << endl;

  for(int i = guy.size(); i < n + guy.size(); i++) {
    cout << "Person " << i + 1 << ": ";

    if(n >= guy.size()) guy.push_back(); //push empty guy in hopefully

    cin >> guy[i].l_name >> guy[i].f_name >> guy[i].birth_month >> guy[i].birth_day
        >> guy[i].birth_year;
  }

}

void big_switch(vector<Soccer_player> &team)
{
  int choice;

  cout << "Choose an option," << endl << "(1 - Input data, 2 - display original"
       << " data, 3 - sort data by last name, 4 - display sorted data 5 - "
       << "search by last name 6 -display goodbye message and exit the program)"
       << endl; 

  cin >> choice;

  switch(choice) {
    case 1:
      fill_player(team);
      break;
    case 2:
      display(team);
      break;
    case 3:
      cout << "Trust me it was sorted..." << endl;
      break;
    case 4:
      display_sorted(team);
      break;
    case 5:
      my_search(team);
      break;
    case 6:
      return 0;
  }
  return 1;
}

void display(vector<Soccer_player> const &team)
{
  for(int i = 0; i < guy.size(); i++) {
    printf("Guy #%d\nName: %s %s\nBirth data: %d/%d/%d\n", i, team[i].f_name,
        team[i].l_name, team[i].birth_month, team[i].birth_day,
        team[i].birth_year);
  }
}


void display_sorted(vector<Soccer_player> team)
{
  sort(team.begin(), team.end(), soc_cmp);

  for(int i = 0; i < guy.size(); i++) {
    print_guy(team[i]);
  }
}


int soc_cmp(const Soccer_player a, const Soccer_player b)
{
  return a.l_name < b.l_name;
}

int soc_cmp_v(const void * a, const void * b)
{
  return (*(Soccer_player)a).l_name - (*(Soccer_player)b).l_name;
}

void my_search(vector<Soccer_player> team)
{
  string temp;
  Soccer_player guy, *found = 0;//set to null

  sort(team.begin(), team.end(), soc_cmp);
  cin >> temp;
  
  while(temp != "//"){
    guy.l_name = temp;
    found = bsearch(&guy, &team[0], team.size(), sizeof(Soccer_player), 
                    soc_cmp_v);
    if(found == 0)
      cout << "Not found" << endl;
    else
      display_guy(*found);
  }
}

void display_guy(const Soccer_player &guy)
{

    printf("Guy #%d\nName: %s %s\nBirth data: %d/%d/%d\n", i, guy.f_name,
        guy.l_name, guy.birth_month, guy.birth_day,
        guy.birth_year);
}
