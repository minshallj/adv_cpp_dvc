#include "prime.h"
#include <stdlib.h>
#define SIZE 100

using namespace std;


int main(int argc, char * argv[])
{
	int index = 0, max_size;
	int * arr;
	if (argc < 2)
		max_size = SIZE;
	else
		max_size = atoi(argv[1]);

	arr = (int*) malloc(max_size * sizeof(int));

	fill_arr(arr, index, max_size);
	print_arr(arr, index);

	return 0;
}
