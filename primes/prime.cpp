#include "prime.h"
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>


void fill_arr(int *arr, int &size, int max_size)
{
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
}

void print_arr(const int *arr, int size)
{
	for(int i = 0; i < size; i++){
		printf("%d\t", arr[i]);
		if(i % 5 == 4) printf("\n");
	}
}
