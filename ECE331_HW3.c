// Sonny Ji
// ECE331
// Homework #3
// Problem(s): 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* maximum_subarray(int A, int length) {
	// temp is the sum accumulator variable
	// out is the largest sum as of right now
	// ii is the start of the maximum subarray
	// jj is the end of the maximum subarray
	int temp = 0;
	int out = 0;
	int ii = 0;
	int jj = 0;
	for(int i = 0; i < length; i++) {
		temp = 0;
		for(int j = i; j < length; j++) {
			temp += A[j];
			if(temp > out) {
				// Hold the largest sum so far, as well as the location of the indicies
				out = temp;
				ii = i;
				jj = j;
			}
		}
	}
	int ret[3];
	ret[1] = out;
	ret[2] = ii;
	ret[3] = jj;
	return ret;
}

int main() {
	int A[16];
	// [Initialize array here]
	int length = sizeof(A) / sizeof(A[0]);
	int* maximum_subarray;
	maximum_subarray = maximum_subarray(A, length);
	printf("The maximum subarray is %d, in [%d, %d]\n", maximum_subarray[1], maximum_subarray[2], maximum_subarray[3]);
}