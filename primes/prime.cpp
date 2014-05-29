#include "prime.h"
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>


int fill_arr(int *arr, int max_size)
{
	int size = 0;

	if (max_size <= 2)
		return 0;

	arr[size++] = 2;
	for(int i = 3; i < max_size; i++){
		for(int j = 2; j < i; j++){
			if(i % j == 0)
				break;
			if(j == size - 1 || j > sqrt(i)){ /*last pass*/
				arr[size++] = i;
				break;
			}
		}
	}

	return size;
}

void print_arr(const int *arr, int size)
{
	for(int i = 0; i < size; i++){
		printf("%d\t", arr[i]);
		if(i % 5 == 4) printf("\n");
	}
}

/* Jason Mobarak (@silverjam) had some name for this, sounded
 * like the gesundheit or something... I could be diligent and
 * look it up */
int gesundheit_prime(int *primes, int max_size)
{
	int *data, n_primes, i, tmp;

	n_primes = 0;
	/* fill with zeros for this to work */
	data = (int*)malloc(max_size * sizeof(int));
	bzero(data, max_size * sizeof(int));

	for (i = 2; i < max_size; i++) {
		if (data[i] == 0) {
			primes[n_primes++] = i;
			tmp = i;
			/* insert all multiples of i into data
			 * i'm pretty sure this only needs to be done
			 * for primes, since all non primes have a prime
			 * as a factor <-- I think... i'm not a mathy person*/
			while (tmp < max_size) {
				/* mark spot as filled */
				data[tmp] = 1;
				tmp += i;
			}
		}
	}

	return n_primes;
}
