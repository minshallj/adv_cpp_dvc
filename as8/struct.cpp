// jacob minshall
// struct.cpp

// soccer players, and their information
// takes user input on 10 soccer players, and then searches for another
// user input soccer player

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct
{
  string l_name;
  string f_name;
  int birth_month;
  int birth_day;
  int birth_year;
}Soccer_player;


//function prototypes
void fill_player(Soccer_player **guy, int &size, int &max, int n = 1);
int big_switch(Soccer_player **team, int &logical, int &max);
void display(Soccer_player *team, int logical);
void display_sorted(Soccer_player *team, int logical);
int soc_cmp(const void * a, const void * b);
void display_guy(Soccer_player *guy);
void my_search(Soccer_player *team, int logical);


int main()
{
  int size = 0, fill = 3, max = 3;

  Soccer_player *team = new Soccer_player[max];

  fill_player(&team, size, max, fill);
  
  while(big_switch(&team, size, max))
    ;
  
  return 0;
}

void fill_player(Soccer_player **guy, int &size, int &max, int n)
{
  cout << "Please enter last name, first name, birth month(1-12), birth date(1-31) ";
  cout << "and birth year seperated by spaces: " << endl;

  for(int i = size; i < (n + size); i++) {
    cout << "Person " << i + 1 << ": ";

    if(i >= max){
      Soccer_player *temp = new Soccer_player[max * 2];
      for(int j = 0; j < max; j++)
        temp[j] = (*guy)[j];
      //delete [] *guy;
      max *= 2;
      *guy = temp;
    }

    cin >> (*guy)[i].l_name >> (*guy)[i].f_name >> (*guy)[i].birth_month >> (*guy)[i].birth_day
        >> (*guy)[i].birth_year;
  }

  size += n;
}

int big_switch(Soccer_player **team, int &logical, int &max)
{
  int choice;

  cout << "Choose an option," << endl << "(1 - Input data, 2 - display original"
       << " data, 3 - sort data by last name, 4 - display sorted data 5 - "
       << "search by last name 6 -display goodbye message and exit the program)"
       << endl; 

  cin >> choice;

  switch(choice) {
    case 1:
      fill_player(team, logical, max);
      break;
    case 2:
      display(*team, logical);
      break;
    case 3:
      cout << "Trust me it was sorted..." << endl;
      break;
    case 4:
      display_sorted(*team, logical);
      break;
    case 5:
      my_search(*team, logical);
      break;
    case 6:
      cout << "Nice time soccering with you" << endl;
      return 0;
  }
  return 1;
}

void display(Soccer_player *team, int logical)
{
  for(int i = 0; i < logical; i++) {
    display_guy(&team[i]);
  }
}


void display_sorted(Soccer_player *team, int logical)
{
  Soccer_player *temp = new Soccer_player[logical];
  for(int i = 0; i < logical; i++)
    temp[i] = team[i];
  qsort(temp, logical, sizeof(Soccer_player), soc_cmp);

  for(int i = 0; i < logical; i++) {
    display_guy(&temp[i]);
  }

  //delete [] temp;
}


int soc_cmp(const void * a, const void * b)
{
  return (*(Soccer_player*)a).l_name.compare((*(Soccer_player*)b).l_name);

}


void my_search(Soccer_player *team, int logical)
{
  string stemp;
  Soccer_player guy, *found = 0;//set to null

  Soccer_player *temp = new Soccer_player[logical];
    for(int i = 0; i < logical; i++)
      temp[i] = team[i];
  qsort(temp, logical, sizeof(Soccer_player), soc_cmp);

  cout << "Enter name: ";
  cin >> stemp;
  
  while(stemp != "//"){
    guy.l_name = stemp;
    found = (Soccer_player*)bsearch(&guy, temp, logical, sizeof(Soccer_player), 
            soc_cmp);
    if(found == 0)
      cout << "Not found" << endl;
    else
      display_guy(found);

    cout << "Enter name: ";
    cin >> stemp;
  }
}

void display_guy( Soccer_player *guy)
{

  /*printf("Name: %s %s\nBirth data: %d/%d/%d\n", guy->f_name,
      guy->l_name, guy->birth_month, guy->birth_day,
      guy->birth_year);*/
  cout << "Name: " << guy->f_name << " " << guy->l_name << endl;
  cout << "Birth date: " << guy->birth_month << "/" << guy->birth_day
       << "/" << guy->birth_year << endl;
}