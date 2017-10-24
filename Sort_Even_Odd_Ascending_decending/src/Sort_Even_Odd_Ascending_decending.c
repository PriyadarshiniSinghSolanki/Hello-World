/*
 ============================================================================
 Name        : Sort_Even_Odd_Ascending_decending.c
 Author      : Priyadarshini Singh Solanki
 Version     :
 Copyright   : Your copyright notice
 Description : Sort all even numbers in ascending order and then sort all odd numbers in descending order
 Input  : arr[] = {1, 2, 3, 5, 4, 7, 10}
 Output : arr[] = {7, 5, 3, 1, 2, 4, 10}

 Input  : arr[] = {0, 4, 5, 3, 7, 2, 1}
 Output : arr[] = {7, 5, 3, 1, 0, 2, 4}
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int arr[7] = { 1, 2, 3, 5, 4, 7, 10 };
	int arr_even[7], arr_odd[7];
	int i, j, temp;
	static int k, l;
	for (i = 0; i < 7; ++i) {
		if ((arr[i] % 2) == 0) {
			arr_even[k] = arr[i];
			k++;
		} else {
			arr_odd[l] = arr[i];
			l++;
		}
	}

	for (i = 0; i < (k - 1); ++i) {
		for (j = i + 1; j < k ; ++j) {
			if (arr_even[i] > arr_even[j]) {
				temp = arr_even[i];
				arr_even[i] = arr_even[j];
				arr_even[j] = temp;
			}
		}

	}
	for (i = 0; i < (l - 1); ++i) {
		for (j = i + 1; j < l; ++j) {
			if (arr_odd[i] < arr_odd[j]) {
				temp = arr_odd[i];
				arr_odd[i] = arr_odd[j];
				arr_odd[j] = temp;
			}
		}
	}

	for (i = 0; i < l; ++i) {
		printf("%d ", arr_odd[i]);
	}
	for (i = 0; i < k; ++i) {
		printf("%d ", arr_even[i]);
	}

	return 0;
}
