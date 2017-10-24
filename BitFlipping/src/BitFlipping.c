/*
 ============================================================================
 Name        : BitFlipping.c
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

#if 1
int nochange_bits(char* input1, int input2, int input3) {
	int i;
	int input4 = 0;
	static int temp, same, cnt;
	while (*input1) {
		cnt++;
		input4 *= 2;
		if (*input1++ == '1')
		input4 += 1;
	}
	if ((input2 > cnt) && (input2 == 0) && (input3 > cnt) && (input3 == 0))
	return -1;

	temp = input4;
	for (i = 0; i < cnt; i++) {
		temp = temp ^ (1 << i);
	}
	int tempInput2 = input2;
	for (i = 0; i < cnt; i++) {
		if ((i + 1) == tempInput2) {
			temp = temp ^ (1 << i);
			tempInput2 = tempInput2 + input2;
		}
	}
	int tempInput3 = input3;
	for (i = 0; i < cnt; i++) {
		if ((i + 1) == tempInput3) {
			temp = temp ^ (1 << i);
			tempInput3 = tempInput3 + input3;
		}
	}
	for (i = 0; i < cnt; i++) {
		if (((temp & (1 << i)) ^ (input4 & (1 << i))) == 0) {
			same++;
		}
	}
	return same;
}
#endif
#if 0
int nochange_bits(char* input1, int input2, int input3) {
	int i;
	int input4 = 0;
	static int temp, same = 1, cnt;
	int tempInput2 = input2, tempInput3 = input3;
	while (*input1) {
		cnt++;
		input4 *= 2;
		if (*input1++ == '1')
			input4 += 1;
	}
	if ((input2 > cnt) && (input2 == 0) && (input3 > cnt) && (input3 == 0))
		return -1;

	temp = input4;

	for (i = 0; i < cnt; i++) {
		temp = temp ^ (1 << i);
		if ((i + 1) == tempInput2) {
			temp = temp ^ (1 << i);
			tempInput2 = tempInput2 + input2;
		}
		if ((i + 1) == tempInput3) {
			temp = temp ^ (1 << i);
			tempInput3 = tempInput3 + input3;
		}
		if (((temp & (1 << i)) ^ (input4 & (1 << i))) == 0) {
			same++;
		}
	}

	return same;
}
#endif
#if 0
int nochange_bits1(char* input1, int input2, int input3) {
	int i;
	int input4 = 0;
	static int temp, same = 1, cnt = 1;
	while (*input1) {
		cnt++;
		input4 *= 2;
		if (*input1++ == '1')
		input4 += 1;
		temp = input4;
		int tempInput2 = input2, tempInput3 = input3;
		if ((input2 > cnt) && (input2 == 0) && (input3 > cnt) && (input3 == 0))
		return -1;
		temp = temp ^ (1 << i);
		if ((i + 1) == tempInput2) {
			temp = temp ^ (1 << i);
			tempInput2 = tempInput2 + input2;
		}
		if ((i + 1) == tempInput3) {
			temp = temp ^ (1 << i);
			tempInput3 = tempInput3 + input3;
		}
		if (((temp & (1 << i)) ^ (input4 & (1 << i))) == 0) {
			same++;
		}
	}

	return same;
}
#endif
int main() {
	int output = 0;
	char* ip1;
	ip1 = (char *) calloc(512000, sizeof(char));
	scanf("\n%[^\n]", ip1);
	int ip2;
	scanf("%d", &ip2);
	int ip3;
	scanf("%d", &ip3);
	output = nochange_bits(ip1, ip2, ip3);
	printf("%d\n", output);
	return 0;
}
