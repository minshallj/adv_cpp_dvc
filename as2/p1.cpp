// program: p1.cpp
// name: jacob minshall

#include <stdio.h>
#include <iostream>
#define SIZE 100
using namespace std;

//void get_input(int * person);
void draw_hist(int students[], int size);
int main()
{
  int students[SIZE];
  int count = 0;
  cout << "Please enter favorite drink, 1=coffee 2=tea ";
  cout << "3=coke 4=orance juice: "<< endl;
  while (1){
    cout << "Enter value for person " << count+1 << " or press -1 to quit: ";
    //get_input(&students[count]);
    cin >> students[count];
    if(students[count] == -1) break;
    else if (students[count] > 4 || students[count] < 1) continue;//no count inc
    count++;
  } //at this point count should be equal to the amount of valid
    //values inside students since the count[th] index will be -1

  draw_hist(students, count); 
}

/*
void get_input(int * person)
{
  cin >> *person;
}
*/

void draw_hist(int students[], int count)
{
  int a=1, b=2, c=3, d=4;
  int arr[4];
  for (int i = 0; i < 4; i++) arr[i]=0;
  for(int i = 0; i < count; i++){
    switch(students[i]){
      case 1: arr[a-1]++; break;
      case 2: arr[b-1]++; break;
      case 3: arr[c-1]++; break;
      case 4: arr[d-1]++; break;
      default: cout << "no " << students[i] << " in switch for student " << i << endl;
    } 
  }
  // this for loop takes the ascii value of 'a' and adds i to it which will
  // on the final loop print d and then sends into another for loop which will
  // take the address of the first integer made, and subtract i from that with
  // pointer arithimitic, and then whatever that address points to, ie either
  // variables a b c or d, and then initialize i to be that value and print
  // asterisks until i is depleted to zero
  for(int i = 0; i < 4; i++){
    cout << (char)((int)'a'+i);
    for(int j = arr[i]; j > 0; j--)
      cout << "*";
    cout << endl;
  }
    

}

