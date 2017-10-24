/*
 ============================================================================
 Name        : Shortest_Path.c
 Author      : Priyadarshini Singh Solanki
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 va_start - which initializes the list
 va_arg - which returns the next argument in the list
 va_end - which cleans up the variable argument list.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


#define ROW 3
#define COLOUM 3

int min(int numargs, ...);
int min(int numargs, ...) {
	va_list arguments;
	va_start(arguments, numargs);
	int i;
	int minimum = va_arg(arguments, int);
	for (i = 0; i < numargs - 1; i++) {
		int next = va_arg(arguments, int);
		minimum = minimum < next ? minimum : next;
	}
	va_end(arguments);
	return minimum;
}

int main(void) {
	puts("!!!Hello World!!!");
	int i, j;
	int temp_Arr[ROW][COLOUM];
	/*int arr[ROW][COLOUM] = { { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 }, { 1, 0, 1, 0, 1,
			1, 1, 0, 1, 1 }, { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 }, { 0, 0, 0, 0, 1,
			0, 0, 0, 0, 1 }, { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 }, { 1, 0, 1, 1, 1,
			1, 0, 1, 0, 0 }, { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, { 1, 0, 1, 1, 1,
			1, 0, 1, 1, 1 }, { 1, 1, 0, 0, 0, 0, 1, 0, 0, 1 } };*/
	//int arr[ROW][COLOUM] = {{1,0,0,0,0,0},{1,1,1,1,1,1},{0,1,0,0,0,1},{0,1,0,0,0,1},{1,1,1,0,1,3},{0,0,1,1,1,0}};
	//int arr[ROW][COLOUM] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13,14, 15, 16 } };
	//int arr[ROW][COLOUM] = { { 1, 3, 5, 8 }, { 4, 2, 1, 7 }, { 4, 3, 2, 3 } };
	//int arr[ROW][COLOUM] = { {5,7,2,4 }, { 1,8,1,3 }, {6,2,9,5},{1,6,2,8}};
	int arr[ROW][COLOUM] = { { 1, 2, 3 }, { 4, 8, 2 }, { 1, 5, 3 } };
	temp_Arr[0][0] = arr[0][0];

	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COLOUM; j++) {
			printf("%d, ", arr[i][j]);
		}
		printf("\n");
	}
	for (i = 1; i < ROW; i++) {
		temp_Arr[i][0] = temp_Arr[i - 1][0] + arr[i][0];
	}

	for (j = 1; j < COLOUM; j++) {
		temp_Arr[0][j] = temp_Arr[0][j - 1] + arr[0][j];
	}

	for (i = 1; i < ROW; i++) {
		for (j = 1; j < COLOUM; j++) {
			temp_Arr[i][j] = (int) min(2, temp_Arr[i - 1][j],temp_Arr[i][j - 1]) + arr[i][j];
		}
	}
	printf("\n");
	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COLOUM; j++) {
			printf("%d, ", temp_Arr[i][j]);
		}
		printf("\n");
	}

	int m = ROW-1, n = COLOUM-1;
	//printf("%d ", arr[ROW-1][COLOUM-1]);
	static int sum;
	sum = arr[ROW-1][COLOUM-1];
	while (j) {
		i = m, j = n;
		int var = min(3, temp_Arr[i - 1][j], temp_Arr[i][j - 1],temp_Arr[i - 1][j - 1]);
		if (var == temp_Arr[i - 1][j - 1]) {
			m = i - 1;
			n = j - 1;
			//printf("%d ",arr[i - 1][j - 1]);
			sum += arr[i - 1][j - 1];
		} else if (var == temp_Arr[i - 1][j]) {
			m = i - 1;
			n = j;
			//printf("%d ",arr[i - 1][j]);
			sum += arr[i - 1][j];
		} else if (var == temp_Arr[i][j - 1]) {
			m = i;
			n = j - 1;
			//	printf("%d ", arr[i][j - 1]);
			sum += arr[i][j - 1];
		}
		if ((i == 0) && (j == 0))
			break;
	}
	printf("sum:%d", sum);
	return EXIT_SUCCESS;
}

