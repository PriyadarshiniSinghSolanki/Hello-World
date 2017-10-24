/*
 ============================================================================
 Name        : Sorting.c
 Author      : Priyadarshini Singh Solanki
 Version     :
 Copyright   : Your copyright notice
 Description : 	Selection sort: repeatedly pick the smallest element to append to the result.
 	 	 	 	Insertion sort: repeatedly add new element to the sorted result.
 	 	 	 	Bubble sort: repeatedly compare neighbor pairs and swap if necessary.
 ============================================================================
 */

#ifndef BUBBLESORT
#define BUBBLESORT
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int i, j, n, temp;
	scanf("%d", &n);
	int a[n];
	static int cnt;
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 0; i < n; i++) {
		// Track number of elements swapped during a single array traversal
		int numberOfSwaps = 0;
		for (j = 0; j < n - 1; j++) {
			// Swap adjacent elements if they are in decreasing order
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				numberOfSwaps++;
				cnt++;
			}
		}
		if (numberOfSwaps == 0) {
			break;
		}
	}
	// If no elements were swapped during a traversal, array is sorted

	printf("%d", cnt);
	return EXIT_SUCCESS;
}
#endif


