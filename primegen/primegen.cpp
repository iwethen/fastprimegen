// primegen.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <math.h>
#include <time.h> 
#include <stdlib.h>
#define limit 1000000000/2   // 1000000000 is Upper limit of prime numbers

long* nums = (long*)malloc(limit * sizeof(long));
long* primes = (long*)malloc(limit * sizeof(long));
int main()
{
	clock_t t;
	t = clock();
	//fill array nums with odd numbers
	for (long i = 0; i < limit; i++) {
		nums[i] = 2*i+3;
	}
	double sqrtlimit = sqrt(limit);
	// remove all the numbers that is equal to multiply of a prime number
	for (long i = 0; i < sqrtlimit; i++) {
		long k = 1;
		if (nums[i] != 0) {
			while (i+nums[i] * k < limit) {
				nums[i+nums[i] * k] = 0;
				k += 1;
			}
		}
	}

	// add 2 to prime numbers array primes
	primes[0] = 2;
	long primecount = 1;
	// add other prime numbers to array primes
	for (long i = 0; i < limit-1; i++) {
		if (nums[i] != 0) {
			primes[primecount] = nums[i];
			primecount++;
		}
	}
	t = clock() - t;
	double time_taken = ((double)t) / CLOCKS_PER_SEC;
	printf("\n took %f seconds to generate \n", time_taken);
	


	for (long i = primecount -10; i <primecount; i++) {
		printf("%d\t",primes[i]);
	}
	printf("\nPress Any Key to Continue\n");
	getchar();
	return 0;
}

