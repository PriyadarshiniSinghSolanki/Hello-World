/*
 ============================================================================
 Name        : CharToBinary.c
 Author      : Priyadarshini Singh Solanki
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
	char output[10] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
			0x09 };
	int i;
	static int cnt;
	char *arr = malloc(sizeof(char*) * 10);
	for (i = 0; i < 10; ++i) {
		itoa(output[i], arr, 2);
		printf("%s ", arr);
		while (*arr)
			if (*arr == '1') {
				cnt++;
				arr++;
			} else
				arr++;
	}

	printf("number of 1's : %d", cnt);
	printf("\n");
	printf("number of 0's : %d", 80 - cnt);

	return 0;
}
