/*
 ============================================================================
 Name        : UUDDDUD.c
 Author      : Priyadarshini Singh Solanki
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
Input: 8 UDDDUDUU
Explaination:
  _/\      _
   	 \    /
      \/\/


* A mountain is a non-empty sequence of consecutive steps above sea level,
starting with a step up from sea level and ending with a step down to sea level.
* A valley is a non-empty sequence of consecutive steps below sea level,
* starting with a step down from sea level and ending with a step up to sea level.
*/
#define UD
#ifdef UD
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	/*Enter your code here. Read input from STDIN. Print output to STDOUT*/
	long int n, var;
	static long int cnt, prev, max;
	scanf("%ld", &n);
	char str[n + 1];
	scanf("%s", str); //DDUUDDUDUUUD
	for (var = 0; var < n; ++var) {
		prev = cnt;
		if (*(str + var) == 'U') {
			cnt++;
		} else if (*(str + var) == 'D') {
			cnt--;
		}
		if (cnt == 0 && prev < 0)
			max++;
	}
	printf("%ld", max);
	return 0;
}
#endif
