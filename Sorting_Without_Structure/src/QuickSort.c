/*
 * QuickSort.c
 *
 *  Created on: 20-Sep-2017
 *      Author: Sys-5304
 */

#include <stdio.h>
#include <stdbool.h>
#define MAX 7

int arr[MAX] = { 4, 6, 13, 2, 22, 9, 7 };
int i;
int partition(int low, int high, int pivot) {
	int lowPointer = low - 1;
	int highPointer = high;
	int temp;
	while (1) {
		while (arr[++lowPointer] < pivot) {

		}

		while (highPointer > 0 && arr[--highPointer] > pivot) {
		}

		if (lowPointer >= highPointer) {
			break;
		} else {
			temp = arr[lowPointer];
			arr[lowPointer] = arr[highPointer];
			arr[highPointer] = temp;
		}
	}

	temp = arr[lowPointer];
	arr[lowPointer] = arr[high];
	arr[high] = temp;
	return lowPointer;
}

void quickSort(int low, int high) {
	if (high - low <= 0) {
		return;
	} else {
		int pivot = arr[high];
		int partitionPoint = partition(low, high, pivot);
		quickSort(low, partitionPoint - 1);
		quickSort(partitionPoint + 1, high);
	}
}

int main() {
	quickSort(0, MAX - 1);
	for (i = 0; i < MAX; ++i) {
		printf("%d ", arr[i]);
	}

	return 0;
}


