/*
 ============================================================================
 Name        : ThristyCrow_Problem.c
 Author      : Priyadarshini Singh Solanki
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#ifdef POT
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
int ThirstyCrowProblem(int input1_size, int* input1, int input2) {
	int i, j;
	int temp;
	int static sum;
	if (input1 == NULL || input2 < 0 || input2 > input1_size
			|| input1_size <= 0) {
		return -1;
	}
	if (input2 == 0)
	return 0;
	for (i = 0; i < input1_size - 1; ++i) {
		for (j = 0; j < input1_size; ++j) {
			if (input1[i] > input1[j]) {
				temp = input1[i];
				input1[i] = input1[j];
				input1[j] = temp;
			}
		}
	}
	for (i = 0; i < input2; ++i) {
		sum = sum + input1[i];
	}
	return sum;
}
int main() {
	int output = 0;
	int ip1_size = 0;
	int ip1_i;
	scanf("%d\n", &ip1_size); //total pot
	int ip1[ip1_size];// water in pot
	for (ip1_i = 0; ip1_i < ip1_size; ip1_i++) {
		int ip1_item;
		scanf("%d", &ip1_item);

		ip1[ip1_i] = ip1_item;
	}
	int ip2;
	scanf("%d", &ip2); // number of pot crow wants to overflow
	output = ThirstyCrowProblem(ip1_size, ip1, ip2);
	printf("%d\n", output);
	return 0;
}
#endif
