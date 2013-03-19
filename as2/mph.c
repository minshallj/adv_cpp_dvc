// mph.c
// jacob minshall
//
#include <iostream>
#include <stdio.h>
using namespace std;

//function prototypes
template <typename elemType>
void prompt_and_store(elemType &miles, elemType &hours);


int main()
{
    int miles, hours;

    prompt_and_store(miles, hours);
    printf("Your speed was %.2f miles per hour\n", (double)miles/(double)hours);

    return 0;
}

template <typename elemType>
void prompt_and_store(elemType &miles, elemType &hours)
{
    cout << "Please enter your miles travled " << endl;
    cin >> miles;
    cout << "Please enter your hours travled " << endl;
    cin >> hours;
}
