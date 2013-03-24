// grades.c
// jacob minshall
//
#include <iostream>
#include <stdlib.h>
using namespace std;
//function prototypes
template <typename elemType>
void do_sum(const elemType * grades, elemType &sum, int size);
template <typename elemType>
void calculate(int n_grades, elemType sum);
//pass dummy variable to let compiler know which type is desired to return
template <typename elemType>
elemType get_input(const elemType theType);
int get_size();


int main()
{
    int *grades, sum, size;

    grades = (int*) malloc(size = get_size());

    for(int i = 0; i < size; i++)
        *(grades + i) = get_input(*grades);

    do_sum(grades, sum, size);
    calculate(size, sum);

    return 0;
}

template <typename elemType>
void do_sum(const elemType * grades, elemType &sum, int size)
{
    sum = 0;
    for(int i = 0; i < size; i++)
        sum += *(grades + i);
}

template <typename elemType>
void calculate(int n_grades, elemType sum)
{
    cout << "The grade is ";

    // divide by n for average, then 10 for easy switching of grades
    switch(sum / (elemType)n_grades / 10){
        case 10:
        case 9:
            cout << "A" << endl;
            break;
        case 8:
            cout << "B" << endl;
            break;
        case 7:
            cout << "C" << endl;
            break;
        case 6:
            cout << "D" << endl;
            break;
        default:
            cout << "F" << endl;
    }
}

template <typename elemType>
elemType get_input(const elemType theType)
{
    elemType dummy;

    cout << "Enter a numeric grade between 0-100" << endl;
    cin >> dummy;

    return dummy;
}

int get_size()
{
    int dummy;

    cout << "Enter the number of grades" << endl;
    cin >> dummy;

    return dummy;
}
