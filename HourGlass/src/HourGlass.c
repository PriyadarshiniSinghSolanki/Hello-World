/*
 ============================================================================
 Name        : HourGlass.c
 Author      : Priyadarshini Singh Solanki
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
Sample Input:   1 1 1 0 0 0
				0 1 0 0 0 0
				1 1 1 0 0 0
				0 0 2 4 4 0
				0 0 0 2 0 0
				0 0 1 2 4 0
Sample Output:19

Explanation:
contains the following hour glasses:
										1 1 1   1 1 0   1 0 0   0 0 0
										  1       0       0       0
										1 1 1   1 1 0   1 0 0   0 0 0

										0 1 0   1 0 0   0 0 0   0 0 0
										  1       1       0       0
										0 0 2   0 2 4   2 4 4   4 4 0

										1 1 1   1 1 0   1 0 0   0 0 0
										  0       2       4       4
										0 0 0   0 0 2   0 2 0   2 0 0

										0 0 2   0 2 4   2 4 4   4 4 0
										  0       0       2       0
										0 0 1   0 1 2   1 2 4   2 4 0

The hourglass with the maximum sum () is:	2 4 4
											  2
											1 2 4
============================================================================ */


#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
	int arr[6][6], maxSum = -36985247, sum, arr_i, arr_j;
	for (arr_i = 0; arr_i < 6; arr_i++) {
		for (arr_j = 0; arr_j < 6; arr_j++) {

			scanf("%d", &arr[arr_i][arr_j]);
		}
	}
	for (int arr_i = 0; arr_i < 6; arr_i++) {
		for (int arr_j = 0; arr_j < 6; arr_j++) {
			if (arr_j + 2 < 6 && arr_i + 2 < 6) {
				sum = arr[arr_i][arr_j] + arr[arr_i][arr_j + 1]	+ arr[arr_i][arr_j + 2]
						+ arr[arr_i + 1][arr_j + 1]
						+ arr[arr_i + 2][arr_j] + arr[arr_i + 2][arr_j + 1]	+ arr[arr_i + 2][arr_j + 2];
				if (sum > maxSum)
					maxSum = sum;
			}
		}
	}
	printf("%d", maxSum);
	return 0;
}
