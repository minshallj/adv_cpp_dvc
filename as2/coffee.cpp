// coffee.cpp
// jacob minshall

#include <iostream>
#define SIZE 4
#define COFFEE 0
#define TEA 1
#define COLA 2
#define SPRITE 3
using namespace std;

// function prototype
void display_message(int *data = 0);
//void print_data(int data[]);


int main()
{
  int arr[4];
  int temp;
  
  // initialize to zero
  for( int i = 0; i < SIZE; i++)
    arr[i] = 0; 

  display_message();
  
  while(1) {
    cout << "Enter favorite drink from drink list: ";
    cin >> temp;
    // initialize to zero
    
    if(temp > 4 || temp < 1)
      break;

    arr[temp-1]++;
  }

  display_message(arr);

  return 0;
}

void display_message(int * data)
{
  cout << "Coffee: " << (data ? *(data+COFFEE): COFFEE) << endl << "Tea : " << (data ? *(data+TEA) : TEA) << endl;
  cout << "Cola: " << (data ? *(data+COLA) : COLA) << endl << "Sprite: " << (data ? *(data+SPRITE) : SPRITE) << endl;
}
