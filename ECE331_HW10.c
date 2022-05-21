// Sonny Ji
// ECE331
// Homework #10
// Problem(s): 1, 2

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Needed for Windows sleep
// Use other for UNIX
//#include <unistd.h>
#include <Windows.h>

// Length of the created array
#define LENGTH 4
#define LENGTH2 16

// Rooted tree node structure
struct node {
	int key;
	struct node* left;
	struct node* right;
	struct node* parent;
};

// Function to make new node
struct node* newNode(int key) {
	struct node* temp = (struct node*) malloc(sizeof(struct node));
	temp -> key = key;
	temp -> left = NULL;
	temp -> right = NULL;
	temp -> parent = NULL;
	return temp;
}

// Function to build a branch of a BST
struct node* buildTreeBranch(int* A, int* i, int low, int high, struct node* parent, int length) {
	int j = 0;
	// If done
	if(((*i >= length) || (*i < 0)) || (low > high)) {
		return NULL;
	}
	// Make root node
	struct node* root = newNode(A[*i]);
	*i = *i + 1;
	// Set parent
	root -> parent = parent;
	// If one element
	if(low == high) {
		return root;
	}
	// Search for element larger than root
	for(j = low; j <= high; ++j) {
		if(A[j] > (root -> key)) {
			break;
		}
	}
	// Divide into subtrees of greater than or less than root
	root -> left = buildTreeBranch(A, i, *i, j - 1, root, length);
	root -> right = buildTreeBranch(A, i, j, high, root, length);
	return root;
}

// Function to build a full BST from an array
struct node* buildTree(int* A, int length) {
	int i = 0;
	return buildTreeBranch(A, &i, 0, length - 1, NULL, length);
}

// Function to print branches of BST
void printBranches(char c, int n) {
	for(int i = 0; i < n; i++) {
		putchar(c);
	}
}

// Function to print the BST in 2D
void printTree(struct node* root, int level) {
	if(root == NULL) {
		printBranches('\t', level);
		puts("~");
	} else {
		printTree(root -> right, level + 1);
		printBranches('\t', level);
		printf("%d\n", root -> key);
		printTree(root -> left, level + 1);
	}
}

// Function to print the BST in a line
void printTreeLine(struct node* root) {
	if(root == NULL) {
		return;
	}
	printTreeLine(root -> left);
	printf("%d ", root -> key);
	printTreeLine(root -> right);
}

// Function to print an array
void printArray(int* A, int length) {
	printf("[");
	for(int i = 0; i < length - 1; i++) {
		printf("%d, ", A[i]);
	}
	printf("%d]\n", A[length - 1]);
}

// Function to randomly permute the array
void permute(int* A, int length) {
	// Wait to randomize time seed
	Sleep(3);
	srand(time(NULL));
	int temp = 0;
	int j = 0;
	for(int i = 0; i < length; i++) {
		j = rand() % length;
		temp = A[j];
		A[j] = A[i];
		A[i] = temp;
	}
}

// Function to swap for exhaustive permutation
void swap(int* A, int i, int j) {
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

// Function to reverse for exhaustive permutation
void reverse(int* A, int n, int length) {
	int i = n;
	int j = length - 1;
	while(i < j) {
		swap(A, i, j);
		i++;
		j--;
	}
}

// Function to exhaustively permute the array
void nextPermutation(int* A, int length) {
	int i = length - 2;
	while((i >= 0) && (A[i + 1] <= A[i])) {
		i--;
	}
	if(i >= 0) {
		int j = length - 1;
		while(A[j] <= A[i]) {
			j--;
		}
		swap(A, i, j);
	}
	reverse(A, i + 1, length);
}

// Function to get the height of a BST
int treeHeight(struct node* root) {
	if(root == NULL) {
		return 0;
	} else {
		return 1 + max(treeHeight(root -> left), treeHeight(root -> right));
	}
}

int main() {
	// Part 1
	// Setting up array
	int A[LENGTH];
	for(int i = 0; i < LENGTH; i++) {
		A[i] = i + 1;
	}
	// Build tree
	struct node* root = newNode(0);
	/*
	// Test print the array
	printArray(A, LENGTH);
	printf("\n\n");
	// Test print the tree in 2D
	printTree(root, 0);
	printf("\n\n");
	// Test print the tree as a line
	printTreeLine(root);
	*/
	// Counter for getting total height
	int heightCounter = 0;
	// Loop through all permutations exhaustively
	for(int i = 0; i < 24 - 1; i++) {
		//printArray(A, LENGTH);
		root = buildTree(A, LENGTH);
		heightCounter += treeHeight(root);
		nextPermutation(A, LENGTH);
	}
	// Calculate and print average
	double heightAverage = (double) heightCounter / 24;
	printf("The average height of a BST with 4 elements is %.2f, which is about 3.33...\n", heightAverage);

	// Part 2
	// Setting up array
	int B[LENGTH2];
	for(int i = 0; i < LENGTH2; i++) {
		B[i] = i + 1;
	}
	// Build tree
	struct node* root2 = newNode(0);
	// Reset height counter
	int heightCounter2 = 0;
	// Loop through 100 random permutations
	for(int i = 0; i < 100; i++) {
		permute(B, LENGTH2);
		root2 = buildTree(B, LENGTH2);
		heightCounter2 += treeHeight(root2);
	}
	// Calculate and print average
	double heightAverage2 = (double) heightCounter2 / 100;
	printf("The average height of a BST with 16 elements is %.2f.\n", heightAverage2);

	return 0;
}