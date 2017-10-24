/*
 ============================================================================
 Name        : LinkList.c
 Author      : Priyadarshini Singh Solanki
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct LinkList {
	int data;
	struct LinkList *next;
};

void print_linklist(struct LinkList *n);
void push(struct LinkList **head_ref, int new_data);
void insert_after(struct LinkList *prev_node, int new_data);
void deletion(struct LinkList **head_ref, int prev_data);

int main() {
	struct LinkList *head = NULL;
	push(&head, 8);
	push(&head, 9);
	push(&head, 10);
	push(&head, 12);
	insert_after(head->next, 11);
	deletion(&head, 9);
	print_linklist(head);
	return 0;
}

void print_linklist(struct LinkList *n) {
	while (n != NULL) {
		printf("%d\n", n->data);
		fflush(stdout);
		n = n->next;
	}
	return;
}
void push(struct LinkList **head_ref, int new_data) {
	struct LinkList *new_node = (struct LinkList*) malloc(
			sizeof(struct LinkList));
	new_node->data = new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;
	return;
}

void insert_after(struct LinkList *prev_node, int new_data) {
	struct LinkList *new_node = (struct LinkList*) malloc(
			sizeof(struct LinkList));
	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}

void deletion(struct LinkList **head_ref, int prev_data) {
	struct LinkList *prev_node, *temp = *head_ref;
	if ((temp != NULL) && (prev_data == temp->data)) {
		*head_ref = temp->next;
		free(temp);
	}
	while ((temp != NULL) && (prev_data != temp->data)) {
		prev_node = temp;
		temp = temp->next;
	}
	prev_node->next = temp->next;
	free(temp);
	return;
}
