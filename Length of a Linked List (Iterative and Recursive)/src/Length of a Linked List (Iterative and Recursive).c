/*
 ============================================================================
 Name        : Length.c
 Author      : Priyadarshini Singh Solanki
 Version     :
 Copyright   : Your copyright notice
 Description : Find Length of a Linked List (Iterative and Recursive)
 Algorithm to find count of nodes.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct Linklist {
	int data;
	struct Linklist *next;
};

void push(struct Linklist** head_ref, int new_data);
void print_list(struct Linklist *n);
//void get_count(struct Linklist *n);

int main(void) {
	struct Linklist *head = NULL;
	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);
	push(&head, 5);
	print_list(head);
	return EXIT_SUCCESS;
}

void push(struct Linklist** head_ref, int new_data) {
	struct Linklist *new_node = (struct Linklist*) malloc(
			sizeof(struct Linklist));
	new_node->data = new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;
	return;
}

void print_list(struct Linklist *n) {
	int static cnt;
	while (n != NULL) {
		printf("%d\r\n", n->data);
		n = n->next;
		cnt++;
	}
	printf("count of nodes : %d",cnt);
}
