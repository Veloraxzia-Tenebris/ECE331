// Sonny Ji
// ECE331
// Final
// Problem(s): 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Needed for Windows sleep
// Use other for UNIX
//#include <unistd.h>
#include <Windows.h>

// Doubly-linked list structure
struct node {
	int key;
	struct node* next;
	struct node* prev;
};

// Function to make new node
struct node* newNode(int key) {
	struct node* temp = (struct node*) malloc(sizeof(struct node));
	temp -> key = key;
	temp -> next = NULL;
	temp -> prev = NULL;
	return temp;
}

// Function to count the length of a list
int countList(struct node* list) {
	// Set counter pointer to head
	struct node* ptr = list;
	// Create output variable
	int out = 1;
	// Check for empty list
	if(!(ptr -> key)) {
		return -1;
	}
	// Loop through the list till NULL
	while((ptr -> next) != NULL) {
		out++;
		ptr = ptr -> next;
	}
	return out;
}

int countAfterList(struct node* list, int search) {
	// Set counter pointer to head + 1
	struct node* ptr = list -> next;
	// Check if next element is search
	if((ptr -> key) == search) {
		// Count elements after search
		return countList(ptr -> next);
		// Check if is last element
		if((ptr -> next) == NULL) {
			return 0;
		}
	}
	// Loop till find search
	else {
		// Find search
		while((ptr -> key) != search) {
			ptr = ptr -> next;
		}
		// Check if is last element
		if((ptr -> next) == NULL) {
			return 0;
		} else {
			// Count elements after search
			return countList(ptr -> next);
		}
	}
	// If error
	return -1;
}

// Function to print each linked list (Skipping the first element)
void printList(struct node* list) {
	// Set counter pointer to head + 1
	struct node* ptr = list -> next;
	// Check for empty list
	if(!(ptr -> key)) {
		printf("The list is empty.\n");
	}
	printf("[");
	// Loop through the list till NULL
	while((ptr -> next) != NULL) {
		printf("%d, ", ptr -> key);
		ptr = ptr -> next;
	}
	printf("%d", ptr -> key);
	printf("]\n");
}

// Function to insert new node at the end of the list
void insertList(struct node* list, int key) {
	// Set counter pointer to head
	struct node* ptr = list;
	// Loop to the end of the list
	while((ptr -> next) != NULL) {
		ptr = ptr -> next;
	}
	// Create a new node
	struct node* temp = newNode(key);
	// Re-link head and new node
	temp -> prev = ptr;
	ptr -> next = temp;
}

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

int main() {
	// Initialize random function
	srand(time(NULL));

	// Count counter
	int count = 0;

	// Loop 100 times
	for(int j = 0; j < 100; j++) {
		// Create random array
		int A[100];
		generateArray(A, 100);
		//printArray(A, 100);

		// Create buckets
		struct node* A0 = newNode(0);
		struct node* A1 = newNode(0);
		struct node* A2 = newNode(0);
		struct node* A3 = newNode(0);
		struct node* A4 = newNode(0);
		struct node* A5 = newNode(0);
		struct node* A6 = newNode(0);
		struct node* A7 = newNode(0);
		struct node* A8 = newNode(0);
		struct node* A9 = newNode(0);

		// Sort into buckets
		for(int i = 0; i < 100; i++) {
			switch(A[i] % 10) {
				case 0: 
					insertList(A0, A[i]);
					break;
				case 1: 
					insertList(A1, A[i]);
					break;
				case 2: 
					insertList(A2, A[i]);
					break;
				case 3: 
					insertList(A3, A[i]);
					break;
				case 4: 
					insertList(A4, A[i]);
					break;
				case 5: 
					insertList(A5, A[i]);
					break;
				case 6: 
					insertList(A6, A[i]);
					break;
				case 7: 
					insertList(A7, A[i]);
					break;
				case 8: 
					insertList(A8, A[i]);
					break;
				case 9: 
					insertList(A9, A[i]);
					break;
			}
		}

		/*
		printList(A0);
		printList(A1);
		printList(A2);
		printList(A3);
		printList(A4);
		printList(A5);
		printList(A6);
		printList(A7);
		printList(A8);
		printList(A9);
		*/

		// Select a random number in the array
		int temp = A[rand() % 99];
		
		// Look for the bucket and count the elements after
		switch(temp % 10) {
				case 0: 
					count += countAfterList(A0, temp);
					break;
				case 1: 
					count += countAfterList(A1, temp);
					break;
				case 2: 
					count += countAfterList(A2, temp);
					break;
				case 3: 
					count += countAfterList(A3, temp);
					break;
				case 4: 
					count += countAfterList(A4, temp);
					break;
				case 5: 
					count += countAfterList(A5, temp);
					break;
				case 6: 
					count += countAfterList(A6, temp);
					break;
				case 7: 
					count += countAfterList(A7, temp);
					break;
				case 8: 
					count += countAfterList(A8, temp);
					break;
				case 9: 
					count += countAfterList(A9, temp);
					break;
			}

			//printf("%d, %d\n", temp, count);
	}

	// Find average
	double average = (double) count / 100;

	// Print average
	printf("The average number for N hat is %.2f.\n", average);

	// Tested output: 
	// The average number for N hat is 5.52.

	return 0;
}