#include "prime.h"
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <stdio.h>
#define SIZE 100

using namespace std;


int main(int argc, char * argv[])
{
	int index = 0, max_size = SIZE, opt, type = 0;
	int * arr;

	while ((opt = getopt(argc, argv, "c:t:")) != -1) {
		switch (opt) {
			case 'c':
				max_size = atoi(optarg);
				break;
			case 't':
				type = atoi(optarg);
				break;
			default: /* '?' */
				fprintf(stderr, "Usage: %s [-t prime_type(1 or 2)] [-c max_size] name\n",
						argv[0]);
				exit(EXIT_FAILURE);
		}
	}

	arr = (int*) malloc(max_size * sizeof(int));

	/* run both, and bzero the array in between to ensure the second
	 * primes function fills the array properly */
	if (type == 0) {
		index = fill_arr(arr, max_size);
		print_arr(arr, index);

		printf("\n");

		bzero(arr, max_size * sizeof(int));
		index = gesundheit_prime(arr, max_size);
		print_arr(arr, index);
	} else if (type == 1) {
		index = fill_arr(arr, max_size);
		print_arr(arr, index);
	} else if (type == 2) {
		index = gesundheit_prime(arr, max_size);
		print_arr(arr, index);
	} else {
		printf("Invalid choice for prime_type");
		return -1;
	}

	return 0;
}
