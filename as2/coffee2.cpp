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
void display_message(int * data = 0);

int main()
{
  int arr[4];
  int temp;
  
  // initialize to zero
  for( int i = 0; i < SIZE; i++)
    arr[i] = 0; 

  display_message();
  
  while(i) {
    cout << "Enter favorite drink from drink list(0 to break): ";
    cin >> temp;
    
    if(temp > 4 || temp < -1)
      continue;
    else if(temp == -1)
      break;

    arr[temp]++;
  }
  display_message(arr);
}

void display_message(int * data)
{
  cout << "Coffee: " << (data ? *(data+COFFEE) : COFFEE << endl << "Tea : " << (data ? *(data+TEA) : TEA << endl;
  cout << "Cola: " << (data ? *(data+COLA) : COLA) << endl << "Sprite: " << (data ? *(data + SPRITE) : SPRITE) << endl;
}
