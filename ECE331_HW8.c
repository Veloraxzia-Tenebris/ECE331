// Sonny Ji
// ECE331
// Homework #8
// Problem(s): 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Needed for Windows sleep
// Use other for UNIX
//#include <unistd.h>
#include <Windows.h>

// Length of the created array
#define LENGTH 100
// Length of the buckets
#define BUCKET_LENGTH 40
// Amount of trials for an average
#define TRIALS 100

// Structure for 2 integers
typedef struct twoBuckets {
	int bucket2;
	int bucket3;
} twoBuckets;

// Function to print an array
void printArray(int* A, int length) {
	printf("[");
	for(int i = 0; i < length - 1; i++) {
		printf("%d, ", A[i]);
	}
	printf("%d]\n", A[length - 1]);
}

// Function to create a random array of 3-digit numbers
void generateArray(int* A, int length) {
	// Initialize random function
	srand(time(NULL));
	for(int i = 0; i < length; i++) {
		// Wait to randomize time seed
		Sleep(3);
		// Generate numbers from 100 to 999
		A[i] = (rand() % 899) + 100;
	}
}

// Function to set all bucket elements to 0
void setZero(int* A, int length) {
	for(int i = 0; i < length; i++) {
		A[i] = 0;
	}
}

// Function to place new element into bucket
void insertElement(int* A, int length, int element) {
	int temp = 0;
	while((A[temp] != 0) && (temp < length)) {
		temp++;
	}
	A[temp] = element;
}

// Function to print non-zero elements of a bucket
void printBucket(int* A, int length) {
	int temp = 0;
	printf("[");
	while((A[temp] != 0) && (temp < length)) {
		printf("%d", A[temp]);
		// To make the output look nice
		if(A[temp + 1] != 0) {
			printf(", ");
		}
		temp++;
	}
	printf("]\n");
}

// Function to count non-zero elements of a bucket
int countBucket(int* A, int length) {
	int temp = 0;
	while((A[temp] != 0) && (temp < length)) {
		temp++;
	}
	return temp;
}

// Function to do Part 1
void makeBuckets(twoBuckets* out) {
	// Create main unsorted array
	int A[LENGTH];
	generateArray(A, LENGTH);
	// Create buckets
	int A0[BUCKET_LENGTH];
	int A1[BUCKET_LENGTH];
	int A2[BUCKET_LENGTH];
	int A3[BUCKET_LENGTH];
	int A4[BUCKET_LENGTH];
	int A5[BUCKET_LENGTH];
	int A6[BUCKET_LENGTH];
	int A7[BUCKET_LENGTH];
	int A8[BUCKET_LENGTH];
	int A9[BUCKET_LENGTH];
	// Empty buckets
	setZero(A0, BUCKET_LENGTH);
	setZero(A1, BUCKET_LENGTH);
	setZero(A2, BUCKET_LENGTH);
	setZero(A3, BUCKET_LENGTH);
	setZero(A4, BUCKET_LENGTH);
	setZero(A5, BUCKET_LENGTH);
	setZero(A6, BUCKET_LENGTH);
	setZero(A7, BUCKET_LENGTH);
	setZero(A8, BUCKET_LENGTH);
	setZero(A9, BUCKET_LENGTH);
	// Test print the array for debugging
	//printArray(A, LENGTH);
	// Sort the array by least significant digit
	for(int i = 0; i < LENGTH; i++) {
		switch(A[i] % 10) {
			case 0: 
				insertElement(A0, BUCKET_LENGTH, A[i]);
				break;
			case 1: 
				insertElement(A1, BUCKET_LENGTH, A[i]);
				break;
			case 2: 
				insertElement(A2, BUCKET_LENGTH, A[i]);
				break;
			case 3: 
				insertElement(A3, BUCKET_LENGTH, A[i]);
				break;
			case 4: 
				insertElement(A4, BUCKET_LENGTH, A[i]);
				break;
			case 5: 
				insertElement(A5, BUCKET_LENGTH, A[i]);
				break;
			case 6: 
				insertElement(A6, BUCKET_LENGTH, A[i]);
				break;
			case 7: 
				insertElement(A7, BUCKET_LENGTH, A[i]);
				break;
			case 8: 
				insertElement(A8, BUCKET_LENGTH, A[i]);
				break;
			case 9: 
				insertElement(A9, BUCKET_LENGTH, A[i]);
				break;
		}
	}
	// Print all the buckets for debugging
	/*
	printf("Bucket 0:\n");
	printBucket(A0, BUCKET_LENGTH);
	printf("Bucket 1:\n");
	printBucket(A1, BUCKET_LENGTH);
	printf("Bucket 2:\n");
	printBucket(A2, BUCKET_LENGTH);
	printf("Bucket 3:\n");
	printBucket(A3, BUCKET_LENGTH);
	printf("Bucket 4:\n");
	printBucket(A4, BUCKET_LENGTH);
	printf("Bucket 5:\n");
	printBucket(A5, BUCKET_LENGTH);
	printf("Bucket 6:\n");
	printBucket(A6, BUCKET_LENGTH);
	printf("Bucket 7:\n");
	printBucket(A7, BUCKET_LENGTH);
	printf("Bucket 8:\n");
	printBucket(A8, BUCKET_LENGTH);
	printf("Bucket 9:\n");
	printBucket(A9, BUCKET_LENGTH);
	printf("Bucket 2 has %d.\n", countBucket(A2, BUCKET_LENGTH));
	printf("Bucket 3 has %d.\n", countBucket(A3, BUCKET_LENGTH));
	*/
	out -> bucket2 = countBucket(A2, BUCKET_LENGTH);
	out -> bucket3 = countBucket(A3, BUCKET_LENGTH);
}

int main() {
	// Create variable for buckets output
	twoBuckets buckets;
	// Do Part 1
	makeBuckets(&buckets);
	printf("For one run, there are %d elements in list 2 and %d elements in list 3.\n", buckets.bucket2, buckets.bucket3);
	// Do Part 2
	// Create variables for averages
	double bucket2 = 0.0;
	double bucket3 = 0.0;
	for(int i = 0; i < TRIALS; i++) {
		makeBuckets(&buckets);
		bucket2 += buckets.bucket2;
		bucket3 += buckets.bucket3;
	}
	bucket2 = bucket2 / TRIALS;
	bucket3 = bucket3 / TRIALS;
	printf("On average, there are %.2f elements in list 2 and %.2f elements in list 3.\n", bucket2, bucket3);
	return 0;
}