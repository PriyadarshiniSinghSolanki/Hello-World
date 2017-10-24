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

void push(struct LinkList **head_ref, int new_data);
void append(struct LinkList **head_ref, int new_data);
void insert_after(struct LinkList *prev_data, int new_data);
void delete(struct LinkList **head_ref, int new_data);
void delete_position(struct LinkList **head_ref, int pos);
void print_list(struct LinkList *n);

int main(void) {
	struct LinkList *head = NULL;
	push(&head, 1);
	push(&head, 3);
	push(&head, 4);
	push(&head, 5);
	push(&head, 6);
	push(&head, 7);
	insert_after(head->next, 10);
	append(&head, 2);
	delete(&head, 5);
	delete_position(&head, 1);
	print_list(head);
	return EXIT_SUCCESS;
}

void push(struct LinkList **head_ref, int new_data) {
	struct LinkList *new_node = (struct LinkList*) malloc(
			sizeof(struct LinkList));
	new_node->data = new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;
	return;
}

void append(struct LinkList **head_ref, int new_data) {
	struct LinkList *new_node = (struct LinkList*) malloc(
			sizeof(struct LinkList));
	struct LinkList *last_node = *head_ref;
	new_node->data = new_data;
	new_node->next = NULL;

	if (head_ref == NULL) {
		*head_ref = new_node;
		return;
	}

	while (last_node->next != NULL) {
		last_node = last_node->next;
	}
	last_node->next = new_node;
	return;
}

void insert_after(struct LinkList *prev_data, int new_data) {
	struct LinkList *new_node = (struct LinkList*) malloc(
			sizeof(struct LinkList));
	new_node->data = new_data;
	new_node->next = prev_data->next;
	prev_data->next = new_node;
}

void delete(struct LinkList **head_ref, int new_data) {
	struct LinkList *temp = *head_ref, *prev_node;
	if ((temp != NULL) && (temp->data == new_data)) {
		*head_ref = temp->next;
		free(temp);
	}
	while ((temp != NULL) && (temp->data != new_data)) {
		prev_node = temp;
		temp = temp->next;
	}
	prev_node->next = temp->next;
	free(temp);
	return;
}

void delete_position(struct LinkList **head_ref, int pos) {
	int i;
	if (*head_ref == NULL)
		return;
	struct LinkList *temp = *head_ref;
	if (pos == 0) {
		*head_ref = temp->next;
		free(temp);
		return;
	}
	for (i = 0; ((temp != NULL) && (i < pos - 1)); i++) {
		temp = temp->next;
	}
	// Store pointer to the next of node to be deleted
	struct LinkList *next = temp->next->next;
	free(temp->next);
	temp->next=next; // Unlink the deleted node from list
	return;

}

void print_list(struct LinkList *n) {
	while (n != NULL) {
		printf("%d\n", n->data);
		fflush(stdout);
		n = n->next;
	}
}
