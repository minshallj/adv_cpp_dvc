// temp.cpp
// jacob minshall
//
// reads up to 10 temperatures
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#define MAX 10

using namespace std;

// function prototypes
void read_inputs(vector<double>& vec);
double average(const vector<double>& vec);

int main()
{
    vector<double> temps;

    read_inputs(temps);
    // standard library algorithm sort
    // with iterator of first & one past last
 //   sort(temps.begin(), temps.end());

    printf("The average is %.2lf degrees\n", average(temps));
}

void read_inputs(vector<double>& vec)
{
    double temp;

    for(int i = 0; i < MAX; i++) {
        cout << "Please enter a temp: ";
        cin >> temp;
        vec.push_back(temp);
    }
}

double average(const vector<double>& vec)
{
    double total = 0;
    int size = vec.size();

    if (size == 0)
        return 0;

    for(int i = 0; i < size; i++)
        total += vec[i];

    return total / (double)size;
}
