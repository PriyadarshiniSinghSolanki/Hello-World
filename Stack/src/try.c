/*
 * try.c
 *
 *  Created on: 23-Dec-2016
 *      Author: Sys-5304
 */
#include <stdio.h>
#include <stdlib.h>

#define SIZE 50
struct stack {
	int arr[SIZE];
	int top;
} S1;

void init_stack(struct stack *ptr) {
	ptr->top = -1;
}
void push(struct stack *ptr, int val) {
	if (ptr->top == SIZE - 1) {
		printf("Stack is full");
		return;
	}
	ptr->top++;
	ptr->arr[ptr->top] = val;
}

int pop(struct stack *ptr) {
	int val;
	if (ptr->top == -1) {
		printf("Stack is empty");
		return 0;
	}

	val = ptr->arr[ptr->top];
	ptr->top--;
	return val;
}

void Display(struct stack *ptr) {
	int i;
	for (i = ptr->top; i >= 0; i--)
		printf("%d\n", ptr->arr[i]);
}

int main() {
	int option, num, element;
	init_stack(&S1);
	while (1) {
		printf("Choose the option:"
				"\n\t1. Insert Item in Stack"
				"\n\t2. Delete item from stack"
				"\n\t3. Display stack"
				"\n\t4. Quit");
		fflush(stdout);
		scanf("%d", &option);
		switch (option) {
		case 1:
			printf("\nEnetr the number, want to insert in stack\n");
			fflush(stdout);
			scanf("%d", &num);
			push(&S1, num);
			break;
		case 2:
			element = pop(&S1);
			printf("\n popped element is : %d\n", element);
			fflush(stdout);
			break;
		case 3:
			printf("\nStack elements are:");
			fflush(stdout);
			Display(&S1);
			break;
		case 4:
			exit(0);

		default: {
			printf("\nPlease select correct option\n");
		//	fflush(stdout);
			exit(0);
			break;
		}
		}
	}
	return 0;
}
