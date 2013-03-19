#include <iostream>
using namespace std;

int main()
{
    int arr[4] = {0, 5, 9, 33};

    int * pint = arr;

    //std::cout << *pint++;
    std::cout << *++pint << endl;
    return 0;
}
