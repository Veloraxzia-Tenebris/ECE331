// Sonny Ji
// ECE331
// Midterm #1
// Problem(s): 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int coincident_search(int* A, int n) {
	int out = 0;
	for(int i = 0; i < n; i++) {
		if(A[i] == i) {
			out++;
		}
	}
	return out;
}

void permute(int* A, int n) {
	srand(time(NULL));
	int temp = 0;
	int j = 0;
	for(int i = 0; i < n; i++) {
		j = rand() % n;
		temp = A[j];
		A[j] = A[i];
		A[i] = temp;
	}
}

int main() {
	int A[8];
	for(int i = 0; i < 8; i++) {
		A[i] = 8 - i;
	}
	int length = sizeof(A) / sizeof(A[0]);
	int permutations = 100;
	int temp = 0;
	for(int i = 0; i < permutations + 1; i++) {
		Sleep(28);
		permute(A, length);
		temp += coincident_search(A, length);
	}
	printf("Average number of coincidences for 100 permutations: %.2f\n", (double)temp / (double)permutations);
	return 0;
}