/*
 ============================================================================
 Name        : Maximum_of_Num.c
 Author      : Priyadarshini Singh Solanki
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style

 Input: 2593
 Output: 95329
 ============================================================================
 */

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

static int find_max_num(int N);
static int find_max_num(int N) {

	/* Write your code here */
	static int n, cnt;
	n = N;
	int arr[65536];
	while (n) {
		arr[cnt] = n % 10;
		n = n / 10;
		cnt++;
	}
	int i, j, temp;
	for (i = 0; i < (cnt - 1); i++) {
		for (j = i + 1; j < cnt; ++j) {
			if (arr[i] < arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	int k = 0;
	for (i = 0; i < cnt; ++i) {
		k = 10 * k + arr[i];
	}
	return k;
}


int main()
{
  int N,ret;
  printf("Enter the Value:"); //535
  scanf("%d",&N);
  ret = find_max_num(N);
  printf("\nMaximum Number: %d", ret); //553

  return 0;
}
