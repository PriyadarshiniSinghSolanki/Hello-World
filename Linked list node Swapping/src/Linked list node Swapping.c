/*
 ============================================================================
 Name        : Linked.c
 Author      : Priyadarshini Singh Solanki
 Version     :
 Copyright   : Your copyright notice
 Description : Swap nodes in a linked list without swapping data

 Input:  10->15->12->13->20->14,  x = 12, y = 20
 Output: 10->15->20->13->12->14

 Input:  10->15->12->13->20->14,  x = 10, y = 20
 Output: 20->15->12->13->10->14

 Input:  10->15->12->13->20->14,  x = 12, y = 13
 Output: 10->15->13->12->20->14
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct LinkedList {
	int data;
	struct LinkedList *next;
};

void push(struct LinkedList **head_ref, int new_data);
void print_list(struct LinkedList *n);
void swap_node(struct LinkedList **head_ref, int data_match1, int data_match2);

int main(void) {
	struct LinkedList *head = NULL;
	push(&head, 10);
	push(&head, 15);
	push(&head, 12);
	push(&head, 13);
	push(&head, 20);
	push(&head, 14);
	print_list(head);
	swap_node(&head, 12, 20);
	printf("Result after swapping: ");
	print_list(head);
	return EXIT_SUCCESS;
}

void push(struct LinkedList **head_ref, int new_data) {
	struct LinkedList *new_node = (struct LinkedList*) malloc(
			sizeof(struct LinkedList));
	new_node->data = new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;
	return;
}

void print_list(struct LinkedList *n) {
	while (n != NULL) {
		printf("%d  ", n->data);
		n = n->next;
	}
	printf("\n");
}

/* Function to swap nodes x and y in linked list by
 changing links */
void swap_node(struct LinkedList **head_ref, int data_match1, int data_match2) {

	// Nothing to do if data_match1 and data_match2 are same
	if (data_match1 == data_match2)
		return;

	// Search for data_match1 (keep track of prev1 and Curr1
	struct LinkedList *curr1 = *head_ref, *prev1 = NULL;
	while (curr1 && (curr1->data != data_match1)) {
		prev1 = curr1;
		curr1 = curr1->next;
	}

	// Search for data_match2 (keep track of prev2 and Curr2
	struct LinkedList *curr2 = *head_ref, *prev2 = NULL;
	while (curr2 && (curr2->data != data_match2)) {
		prev2 = curr2;
		curr2 = curr2->next;
	}

	// If either data_match1 or data_match2 is not present, nothing to do
	if (curr1 == NULL || curr2 == NULL)
		return;

	// If data_match1 is not head of linked list
	if (prev1 != NULL)
		prev1->next = curr2;
	else
		// Else make data_match2 as new head
		*head_ref = curr2;

	// If data_match2 is not head of linked list
	if (prev2 != NULL)
		prev2->next = curr1;
	else
		// Else make data_match1 as new head
		*head_ref = curr1;

	// Swap next pointers
	struct LinkedList *temp = curr2->next;
	curr2->next = curr1->next;
	curr1->next = temp;
}
