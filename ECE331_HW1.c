// Sonny Ji
// ECE331
// Homework #1
// Problem(s): 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Array A
void printArray(int* A, int n) {
	printf("{");
	for(int i = 0; i < n - 1; i++) {
		printf("%d, ", A[i]);
	}
	printf("%d}\n", A[n - 1]);
}

// Array A of size n
int insertionSort(int* A, int n) {
	int temp = 0;
	int temp2 = 0;
	if(n < 2) {
		return temp;
	} else {
		temp = insertionSort(A, n - 1);
		int i = n - 2;
		int k = A[n - 1];
		while(++temp && ((k < A[i]) && (i > -1))) {
			A[i + 1] = A[i];
			i--;
			temp2 = 1;
		}
		// temp counts (i), temp2 makes it (i - 1)
		if(temp2) {
			temp--;
		}
		A[i + 1] = k;
		return temp;
	}
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
	// Setting up array
	int A[16];
	for(int i = 0; i < 16; i++) {
		A[i] = 16 - i;
	}
	int length = sizeof(A) / sizeof(A[0]);

	// Worst case
	printf("Number of comparisons for worst case: %d\n", insertionSort(A, length));

	// Best case
	printf("Number of comparisons for best case: %d\n", insertionSort(A, length));

	// 100 permutations
	int permutations = 100;
	int temp = 0;
	for(int i = 0; i < permutations + 1; i++) {
		// Sleep, since computer runs too fast for srand(time(NULL))
		Sleep(17);
		permute(A, length);
		temp += insertionSort(A, length);
	}
	printf("Average number of comparisons for 100 permutations: %.2f\n", (double)temp / (double)permutations);
	return 0;
}