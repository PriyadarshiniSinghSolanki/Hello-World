/*
 ============================================================================
 Name        : SaveThePrisoner.c
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

int saveThePrisoner(int n, int m, int s) {
	//int sweets = m,prisoner = n,sweets_ate,remaining_sweets,poisioned,id = s;

	int i = 1;
	while (i != m) {
		i++;
		if (n != s)
		s++;
		else
		s = 1;
	}
	return s;
#if 0
	if(sweets > prisoner){
		sweets_ate = prisoner - id;
		remaining_sweets = sweets - sweets_ate;
		poisioned = --remaining_sweets;
	}
	else{
		poisioned = id+ sweets-1;
	}
	return poisioned;
#endif
}

int main() {
	int t;
	scanf("%d", &t);
	for (int a0 = 0; a0 < t; a0++) {
		int n;
		int m;
		int s;
		scanf("%d %d %d", &n, &m, &s);
		int result = saveThePrisoner(n, m, s);
		printf("%d\n", result);
		//fflush(stdout);
	}
	return 0;
}

