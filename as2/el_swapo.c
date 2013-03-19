// el_swapo.c
// jacob minshall
//
#include <iostream>
using namespace std;
//function prototypes
template <typename elemType>
void display(elemType first, elemType second);
template <typename elemType>
void elswap(elemType &first, elemType &second);


int main()
{
    //only static part of program is this double declaration
    double first, second;

    cout << "Enter the first number\nThen hit enter" << endl;
    cin >> first;
    cout << "Enter the second number\nThen hit enter" << endl;
    cin >> second;

    display(first, second);
    elswap(first, second);
    cout << "Swap occured" << endl;
    display(first, second);

    return 0;
}


template <typename elemType>
void display(elemType first, elemType second)
{
    cout << "The values are first " <<  first << " and second " << second << endl;
}

template <typename elemType>
void elswap(elemType &first, elemType &second)
{
    elemType temp = first;
    first = second;
    second = temp;
}
