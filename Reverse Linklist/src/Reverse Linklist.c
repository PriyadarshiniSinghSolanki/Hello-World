/*
 ============================================================================
 Name        : Reverse.c
 Author      : Priyadarshini Singh Solanki
 Version     :
 Copyright   : Your copyright notice
 Description : Function to reverse a linked list
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct Linklist {
	int data;
	struct Linklist *next;
};

void push(struct Linklist **head_ref, int newData) {
	struct Linklist *newNode = (struct Linklist*) malloc(
			sizeof(struct Linklist));
	newNode->data = newData;
	newNode->next = *head_ref;
	*head_ref = newNode;
	return;
}

void printList(struct Linklist *n) {
	while (n != NULL) {
		printf("%d ", n->data);
		n = n->next;
	}
	printf("\n");
}

void reverse_linklist(struct Linklist **head_ref) {
	struct Linklist *current = *head_ref;
	struct Linklist *prev = NULL;
	struct Linklist *next;
	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head_ref = prev;
	return;
}

int main(void) {
	struct Linklist *head = NULL;
	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);
	push(&head, 5);
	push(&head, 6);
	push(&head, 7);
	push(&head, 8);
	printList(head);
	reverse_linklist(&head);
	printList(head);
	return EXIT_SUCCESS;
}
