/*
 * tryPtr.c
 *
 *  Created on: 25-Jul-2017
 *      Author: Sys-5304
 */
#include <stdio.h>
int main() {
	int arr1[5] = { 1, 2, 3, 99, 5 };
	int arr2[2][3] = { { 6, 7, 8 }, { 9, 10, 11 } };
	int arr3[3][2][2] = {
			{{ 12, 13},{ 14, 15 }},
			{{ 16, 17},{ 18, 19 }},
			{{ 20, 21},{ 22, 23 }}
	};

	int *ptr1, (*ptr2)[3], (*ptr3)[2][2];
	ptr1 = arr1;
	ptr2 = arr2;
	ptr3 = arr3;

	printf("%d ", arr1); //6422288
	printf("%d ", &arr1); //6422288
	printf("%d ", *arr1); //1
	printf("%d ", *arr1 + 3); //2
	printf("%d ", arr1 + 1); //6422288+4
	printf("%d ", *(arr1 + 1)); //2
	printf("\t\t");
	printf("%d ", ptr1); //6422288
	printf("%d ", *ptr1); //1
	printf("%d ", ptr1++); //6422288
	printf("%d ", *(ptr1 + 3)); //5
	printf("%d ", *ptr1 + 1); //3

	printf("\n");

	printf("%d ", arr2); //&arr2[0] = 6422264
	printf("%d ", &arr2); //&arr2[0] = 6422264
	printf("%d ", *arr2); //&arr2[0][0] = 6422264
	printf("%d ", arr2 + 1); //&arr2[1] = 6422264+12
	printf("%d ", *(*(arr2 + 1)+1)); //10
	printf("\t");
	printf("%d ", ptr2); //&arr2 = 6422264
	printf("%d ", *ptr2); // 6422264
	printf("%d ", *(ptr2 + 1)); //6422264+12
	printf("%d ", (*ptr2 + 1)); //6422264+4
	printf("%d ", *(*(ptr2 + 1) + 2)); //11

	printf("\n");

	printf("%d ", arr3); //6422216
	printf("%d ", &arr3); //6422216
	printf("%d ", *arr3); //6422216
	printf("%d ", arr3 + 1); //&arr2[1] = 6422264+12
	printf("%d ", **(*(arr3 + 1)+1)); //&arr2[1] = 6422264+12
	printf("\t");
	printf("%d ", ptr3); //&arr2 = 6422216
	printf("%d ", *ptr3); // 6422216
	printf("%d ", *(ptr3 + 1)); //6422216+12
	printf("%d ", *(ptr3 + 2)); //6422216+12+12
	printf("%d ", **(*ptr3 + 1)); //6422264+4
	printf("%d ", *(*(*(ptr3 + 1) + 1))); //11
	return 0;
}



