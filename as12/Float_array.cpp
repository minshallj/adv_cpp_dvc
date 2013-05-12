// Jacob Minshall
// Float_array.cpp
//
// class creating a float array
// accepts integer argument in constructor for member length
// functions:
// store a number in any element
// retrieve a number from any element
// returns highest value
// returns lowest value
// returns average
#include <iostream>
using namespace std;

class Float_array{
  public:
    Float_array(int);
    ~Float_array();

    void add_member(float, int);
    float return_member(int);

    float max();
    float min();
    float mean();
  protected:
    float * arr;
    int allocated_len, filled_len;

    void grow_array();
};

Float_array::Float_array(int n)
{
    if (n < 1)
        exit(1);

    arr = new float[n];
    allocated_len = n;
    filled_len = 0;
}

Float_array::~Float_array()
{
    delete[] arr;
    arr = NULL;
}

/*
 * return if invalid index
 * grow if filled as many as were allocated
 * if putting top value in, grow filled len
 * otherwise overwrite previously stored value
 */
void Float_array::add_member(float value, int i)
{
    if (i < 0 || i > filled_len) {
        cout << "Invalid index" << endl;
        return;
    }
    if (filled_len == allocated_len)
        grow_array();
    if (i == filled_len) {
        arr[filled_len++] = value;
    } else if(i < filled_len)
        arr[i] = value;
}

/*
 * cannot return invalid index, so exit
 * otherwise return that value
 */
float Float_array::return_member(int i)
{
    if (i >= filled_len) {
        cout << "Out of bounds index" << endl;
        exit(1);
    }

    return arr[i];
}

float Float_array::max()
{
    int tmp = arr[0];

    for(int i = 1; i < filled_len; i++)
        if (tmp < arr[i])
            tmp = arr[i];

    return tmp;
}

float Float_array::min()
{
    float tmp = arr[0];

    for(int i = 1; i < filled_len; i++)
        if (tmp > arr[i])
            tmp = arr[i];
}

/*
 * if no elements, return 0
 */
float Float_array::mean()
{
    float sum = 0;

    if (filled_len == 0)
        return 0;

    for(int i = 0; i < filled_len; i++)
        sum += arr[i]

    return sum / (float) filled_len;
}
