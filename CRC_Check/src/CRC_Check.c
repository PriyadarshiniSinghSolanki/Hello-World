/*
 ============================================================================
 Name        : CRC_Check.c
 Author      : Priyadarshini Singh Solanki
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#ifndef CRCCheck
#define CRCCheck
#include<stdio.h>
#include<string.h>
#define N strlen(g)

char t[28], cs[28], g[] = "11011";
int a, e, c;

void xor() {
	for (c = 1; c < N; c++)
		cs[c] = ((cs[c] == g[c]) ? '0' : '1');
}

void crc() {
	for (e = 0; e < N; e++)
		cs[e] = t[e];
	do {
		if (cs[0] == '1')
			xor();
		for (c = 0; c < N - 1; c++)
			cs[c] = cs[c + 1];
		cs[c] = t[e++];
	} while (e <= a + N - 1);
}

int main() {
	scanf("%s\n", t);
	fflush(stdout);
	printf("\nGenerator polynomial : %s\n", g);
	fflush(stdout);

	a = strlen(t);
	for (e = a; e < a + N - 1; e++)
		t[e] = '0';
	printf("data is : %s\n", t);
	crc();
	printf("\nChecksum is : %s", cs);
	for (e = a; e < a + N - 1; e++)
		t[e] = cs[e - a];
	printf("\nFinal codeword is : %s\n", t);
	return 0;
}
#endif
