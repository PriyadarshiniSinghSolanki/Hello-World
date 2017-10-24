/*
 ============================================================================
 Name        : User_Input_Validation.c
 Author      : Priyadarshini Singh Solanki
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<string.h>

int isnum(char *strptr);
int isfloat(char *strptr);
int ischar(char *strptr);

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	char str[100];
	scanf("%s", str);
	printf("string: %s", str);
	if (isnum(str) == 1) {
		printf("This input is of type integer");
	} else if (isfloat(str) == 1) {
		printf("This input is of type float");
	} else if (ischar(str) == 1) {
		printf("This input is of type string");
	} else {
		printf("This input is something else");
	}
	return EXIT_SUCCESS;
}
int isnum(char *strptr) {
	int cnt = 0;
	if ((*strptr == '+') || (*strptr == '-')) {
		strptr++;
		while (*strptr != '\0') {
			if ((*strptr >= '0') && (*strptr <= '9')) {
				strptr++;
				cnt++;

			} else
				return 0;
		}
	} else {
		while (*strptr != '\0') {
			if ((*strptr >= '0') && (*strptr <= '9')) {
				strptr++;
				cnt++;
			} else
				return 0;
		}
	}
	if ((*strptr == '\0') && (cnt > 0))
		return 1;
	return EXIT_SUCCESS;
}

int isfloat(char *strptr) {
	char *ret;
	while (*strptr != '.') {
		if ((*strptr >= '0') && (*strptr <= '9')) {
			strptr++;
		} else
			return 0;
	}
	ret = strchr(strptr, '.');
	if (ret == '\0') {
		return 0;
	} else {

		printf("\r\nret : %s", ret);
		ret++;
		while (*ret != '\0') {
			if ((*ret >= '0') && (*ret <= '9')) {
				ret++;
			} else
				return 0;
		}
		return 1;
	}
	return EXIT_SUCCESS;
}

int ischar(char *strptr) {
	int cnt = 0;
	while (*strptr != '\0') {
		if (((*strptr >= 'A') && (*strptr <= 'Z'))
				|| ((*strptr >= 'a') && (*strptr <= 'z'))) {
			strptr++;
			cnt++;
		} else
			return 0;
	}
	if ((*strptr == '\0') && (cnt > 0))
		return 1;
	return EXIT_SUCCESS;
}

