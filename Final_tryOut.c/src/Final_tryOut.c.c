/*
 ============================================================================
 Name        : c.c
 Author      : Priyadarshini Singh Solanki
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Linkedlist {
	int data;
	struct Linkedlist *next;
};
void push(struct Linkedlist **head_ref, int newdata) {
	struct Linkedlist *newNode = (struct Linkedlist*) malloc(
			sizeof(struct Linkedlist));
	newNode->data = newdata;
	newNode->next = *head_ref;
	*head_ref = newNode;
	return;
}
void reverseLinklist(struct Linkedlist **head_ref) {
	struct Linkedlist *current;
	struct Linkedlist *prev = NULL;
	struct Linkedlist *nextnode;
	current = *head_ref;
	while (current != NULL) {
		nextnode = current->next;
		current->next = prev;
		prev = current;
		current = nextnode;
	}
	*head_ref = prev;

}
void printLinkedlist(struct Linkedlist *head_ref) {
	while (head_ref != '\0') {
		printf("%d ", head_ref->data);
		fflush(stdout);
		head_ref = head_ref->next;

	}
}
int main(void) {
	struct Linkedlist *head = NULL;
	push(&head, 24);
	push(&head, 2);
	push(&head, 5);
	push(&head, 7);
	push(&head, 72);
	push(&head, 34);
	push(&head, 9);
	printLinkedlist(head);
	reverseLinklist(&head);
	printf("\n");
	printLinkedlist(head);
	return EXIT_SUCCESS;
}
