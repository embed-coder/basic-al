/* C++ implementation of QuickSort */
#include <bits/stdc++.h>
using namespace std;

void printarray(int a[], int size);

// A utility function to swap two elements
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition (int a[], int low, int high)
{
	int piv = a[high]; // pivot
	int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot
		printf("i: %d, j: %d, a[j]: %d, a[i]: %d, piv: %d\n", i, j, a[j], a[i], piv);
		printarray(a, high);
		if (a[j] < piv)
		{
			i++; // increment index of smaller element
			swap(&a[i], &a[j]);
		}
		printarray(a, high);
	}
	swap(&a[i + 1], &a[high]);
	printarray(a, high);
	return (i + 1);
}

/* The main function that implements QuickSort
a[] --> array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int a[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, a[p] is now
		at right place */
		int pi = partition(a, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(a, low, pi - 1);
		quickSort(a, pi + 1, high);
	}
}

/* Function to print an array */
void printarray(int a[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << a[i] << " ";
	cout << endl;
}

// Driver Code
int main()
{
	int a[] = {4, 10, 7, 8, 9, 1, 5};
	int n = sizeof(a) / sizeof(a[0]);
	quickSort(a, 0, n - 1);
	cout << "Sorted array: \n";
	printarray(a, n);
	return 0;
}

// This code is contributed by rathbhupendra
