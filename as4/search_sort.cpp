// serch_sort.cpp
// jacob minshall
//
// Takes in array for max length 50, sorts it, and searches
// for a user inputed key with a binary search, then, displays
// mean
//
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#define MAX 50
using namespace std;

void sort_arr(int *arr, int size);
void merge_sort(int *arr, int begin, int end);
void merge(int *arr, int begin, int middle, int end);
int search(int *arr, int key, int size);
int b_search(int *arr, int key, int start, int end);
void display(int *arr, int size);
FILE * open_up(const char * fname, int * size);
void read_file(FILE* file, int *arr, int size);

int main()
{
    int num;
    const int size = 10;
    int arr[size] = {2, 3, 1, 5, 4, 3, 2, 8, 5, 19};
    //FILE *file = open_up("./data.txt", &size);

    //read_file(file, arr, size);

    display(arr, size);
    sort_arr(arr, size);
    display(arr, size);

    cout << "Enter num to search for: ";
    cin >> num;

    cout << "The num is at index " << search(arr, num, size) << endl;

    return 0;
}

// calls merge_sort with proper calls, using beginning index,
// and last useable
void sort_arr(int *arr, int size)
{
    merge_sort(arr, 0, size-1);
}

void merge_sort(int *arr, int begin, int end)
{
    // base case, no distance to split
    if(end - begin < 1) return;
    // halfway past start, +begin offsets
    int middle = (end + begin) / 2;

    merge_sort(arr, begin, middle);
    merge_sort(arr, middle + 1, end);
    merge(arr, begin, middle, end);
}

void merge(int *arr, int begin, int middle, int end)
{
    // temp array to hold merged data
    int * temp = new int[end - begin + 1];
    int l_count = begin, r_count = middle + 1, count = 0;

    // keep setting lower number into temp array
    while(l_count <= middle && r_count <= end){
        if(arr[l_count] < arr[r_count]){
            temp[count] = arr[l_count];
            l_count++;
        }else {
            temp[count] = arr[r_count];
            r_count++;
        }
        count++;
    }
    // adding on whichever array still had more members
    while(l_count <= middle)
        temp[count++] = arr[l_count++];
    while(r_count <= end)
        temp[count++] = arr[r_count++];


    //write over original array
    for(int i = begin, j = 0; i <= end; i++)
        arr[i] = temp[j++];
}


// calls binary search with proper arguments
int search(int *arr, int key, int size)
{
    return b_search(arr, key, 0, size);
}
// binary search, returns index of found or -1 for not there
int b_search(int *arr, int key, int start, int end)
{
    int middle = (start + end) / 2;

    // base case, key found, or nowhere else to check
    if(arr[middle] == key)
        return middle;
    else if(middle == 0)
        return -1;

    // proper recursive call to either second half, or first
    if(arr[middle] < key)
        return b_search(arr, key, middle + 1, end);
    else
        return b_search(arr, key, start, middle - 1);
}
void display(int * arr, int size)
{
    cout << endl;
    for(int i = 0; i < size; i++)
        cout << *(arr + i) << " ";
    cout << endl;
}

// opens up file, stores sentinal value as amount of numbers included
FILE * open_up(const char * fname, int * size)
{
    FILE *fp;
    fp = fopen(fname, "r");
    if(!fp) exit(1); //returning null
    fscanf(fp, "%d\n", size);

    return fp;
}

void read_file(FILE * file, int *arr, int size)
{
    for(int i = 0; i < size; i++)
        fscanf(file, "%d\n", arr+size);
}
