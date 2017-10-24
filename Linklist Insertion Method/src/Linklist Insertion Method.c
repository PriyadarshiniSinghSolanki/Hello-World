/*
 ============================================================================
 Name        : Linklist.c
 Author      : Priyadarshini Singh Solanki
 Version     :
 Copyright   : Your copyright notice
 Description : A complete working C program to demonstrate all insertion methods on Linked List
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct LinkList {
	int data;
	struct LinkList *next;
};

void append(struct LinkList** head_ref, int new_data);
void push(struct LinkList** head_ref, int new_data);
void Insert_After(struct LinkList* head_ref, int new_data);
void PrintList(struct LinkList *n);
int main(void) {
	struct LinkList *Head = NULL;
		append(&Head, 7);
		push(&Head, 8);

		Insert_After(Head->next, 12);
		push(&Head, 9);
		append(&Head, 11);
		push(&Head, 10);
		PrintList(Head);
		return EXIT_SUCCESS;
}

// This function prints contents of linked list starting from head
void PrintList(struct LinkList *n) {
	while (n != NULL) {
		printf("%d\n", n->data);
		fflush(stdout);
		n = n->next;
	}
	return;
}

/*append() function is for inserting data and next =NULL*/
/* Given a reference (pointer to pointer) to the head
 of a list and an int, appends a new node at the end  */
void append(struct LinkList** head_ref, int new_data) {

	struct LinkList* new_node = (struct LinkList*) malloc(
			sizeof(struct LinkList));
	struct LinkList* last_node = *head_ref;

	new_node->data = new_data;

	/* 3. Make next of new node as head/tail*/
	new_node->next = NULL;

	if (*head_ref == NULL) {
		*head_ref = new_node;
		return;
	}
	while (last_node->next != NULL)
		last_node = last_node->next;

	last_node->next = new_node;
	return;
}

/* Given a reference (pointer to pointer) to the head of a list and
 an int, inserts a new node on the front of the list. */
void push(struct LinkList** head_ref, int new_data) {
	/* 1. allocate node */
	struct LinkList* new_node = (struct LinkList*) malloc(
			sizeof(struct LinkList));

	/* 2. put in the data  */
	new_node->data = new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;
	return;
}

/* Given a node prev_node, insert a new node after the given
 prev_node */
void Insert_After(struct LinkList* prev_node, int new_data) {
	if (prev_node == NULL) {
		printf("the given previous node cannot be NULL");
		fflush(stdout);
		return;
	}
	struct LinkList* new_node = (struct LinkList*) malloc(
			sizeof(struct LinkList));
	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
	return;
}
