/*
 * CallBack.c
 *
 *  Created on: 25-Jul-2017
 *      Author: Sys-5304
 */
#include <stdio.h>
void func(void(*p)()){
	p();
}

void Print() {
	printf("Hello\n");
}

int compare(int a, int b) {
	if (a > b)
		return 1;
	else
		return -1;
}

void bubble_sort(int arr[], int n, int (*ptr_compare)(int, int)) {
	int i, j, temp;
	for (i = 0; i < n ; ++i) {
		for (j = 0; j < n-1; ++j) {
			if (ptr_compare(arr[j], arr[j + 1]) > 0) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}

	}
}

int main() {
#if 0
	void(*Ptr_Print)()=Print;
	func(Ptr_Print);
#endif
	func(Print);
	int (*ptr_compare)(int, int);
	ptr_compare = compare;
	int i;
	int arr[] = { 1, 8, 3, 4, 5, 3, 8 };
	int len;
	len = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, len, ptr_compare);
	for (i = 0; i < len; ++i) {
		printf("%d ", arr[i]);
	}
	return 0;
}
