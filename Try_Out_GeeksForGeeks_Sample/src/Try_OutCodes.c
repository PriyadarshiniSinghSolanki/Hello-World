/*
 ============================================================================
 Name        : Try_OutCodes.c
 Author      : Priyadarshini Singh Solanki
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*Calculate Logn in one line*/

/*How to count set bits in a floating point number in C?*/

/* Implement your own itoa()*/

/* Print a long int in C using putchar() only*/

/* Write your own memcpy()*/

// C program to demonstrate use of * for pointers in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*1. Print duplicate characters from String*/

int static cnt;
char* duplicate(char *str, int n) {
	int var, i = 0;
	static char arr[100];
	while (*str != '\0') {
		for (var = 1; var < n; var++) {
			if (*str == *(str + var)) {
				arr[i] = *str;
				i++;
				cnt++;
				break;
			}
		}
		str++;
	}
	return arr;
}

int main(void) {
	/*char *str = "combination";
	char *p;
	int len, var;
	len = strlen(str);
	printf("%d\r\n", len);

	p = duplicate(str, len);
	printf("%d\r\n",cnt);
	if (cnt != 0) {
		for (var = 0; var < cnt; var++) {
			printf("%c ", p[var]);
		}
	} else
	printf("no duplicate word in string");*/

	return EXIT_SUCCESS;
}



