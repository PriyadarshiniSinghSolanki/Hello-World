/*
 ============================================================================
 Name        : Sorting_Using_FunctionPointer.c
 Author      : Priyadarshini Singh Solanki
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include<stdio.h>
#include<stdlib.h>

typedef int (*callback)(int, int);
void insertion_sort(int *array, int n, callback comparison);

void insertion_sort(int *array, int n, callback comparison) {
	int i, j, key;
	for (j = 1; j <= n - 1; j++) {
		key = array[j];
		i = j - 1;
		while (i >= 0 && comparison(array[i], key)) {
			array[i + 1] = array[i];
			i = i - 1;
		}
		array[i + 1] = key;
	}
}

/*insertion_main.c*/
int ascending(int a, int b) {
	return a > b;
}

int descending(int a, int b) {
	return a < b;
}

int even_first(int a, int b) {
	return 0;
}

int odd_first(int a, int b) {
	return 0;
}

int main(void) {
	int i;
	int choice;
	int array[10] = { 22, 66, 55, 11, 99, 33, 44, 77, 88, 0 };
	printf("ascending 1: descending 2: even_first 3: odd_first 4: quit 5\n");
	printf("enter your choice = ");
	scanf("%d", &choice);
	switch (choice) {
	case 1:
		insertion_sort(array, 10, ascending);
		break;
	case 2:
		insertion_sort(array, 10, descending);
		break;
	case 3:
		insertion_sort(array, 10, even_first);
		break;
	case 4:
		insertion_sort(array, 10, odd_first);
		break;
	case 5:
		exit(0);
	default:
		printf("no such option\n");
	}

	printf("after insertion_sort\n");
	for (i = 0; i < 10; i++)
		printf("%d\t", array[i]);
	printf("\n");
	return 0;
}

