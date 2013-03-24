#include <iostream>
#include <algorithm>
using namespace std;

double median(int * arr, int size);
double mean(int * arr, int size);
int mode(int * arr, int size, int * modes);//will return number of modes, and input
// modes into array modes passed
void wipe_out(int * arr, int size);

int main()
{
  int *arr, size, *modes;

  cout << "Please enter size: ";
  cin >> size;

  arr = new int[size];
  modes = new int[size];

  arr[0] = 0; //set for flag checking
  int i = 0;

  for(int i = 0; i < size; i++) {
    cout << "Please enter number of movies watched: ";
	cin >> arr[i];
  }

  cout << "The mean is " << mean(arr, size) << endl;
  cout << "The median is " << median(arr, size) << endl;
  cout << ((size = mode(arr, size, modes)) == 1 ? "The mode is " : "The modes are ");

  for(int i = 0; i < size; i++)
    cout << modes[i] << " ";

  cout << endl;


}

double mean(int * arr, int size)
{
  int sum = 0;

  for(int i = 0; i < size; i++)
    sum += arr[i];

  return (double)sum / size;
}

double median(int * arr, int size)
{
  sort(arr, arr+size);

  return size % 2 == 0 ? (arr[size/2] + arr[size/2 - 1]) / 2 : arr[size/2];
}

int mode(int * arr, int size, int * modes)
{
  int total_modes = 1, n_occurences = count(arr, arr + size, arr[0]), temp, flag;

  modes[0] = arr[0]; //presetting mode to be first

  for(int i = 1; i < size; i++) {
    flag = 1;
    if((temp = count(arr, arr + size, arr[i])) == n_occurences){
      for(int j = 0; j < total_modes; j++)
        if(arr[i] == modes[j])
          flag = 0;
      if(flag) modes[total_modes++] = arr[i];
    }
    else if(temp > n_occurences){
      wipe_out(modes, size);
      n_occurences = temp;
      modes[0] = arr[i];
      total_modes = 1;
      }
  }

  return total_modes;
}

void wipe_out(int * arr, int size){
  for(int i = 0; i < size; i++)
    arr[i] = 0;
}

