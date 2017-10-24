/*
 * Add2Linkedlist.c
 *
 *  Created on: 22-Sep-2017
 *      Author: Sys-5304
 */
#include <stdio.h>
#include <stdlib.h>

struct LinkedList {
	int data;
	struct LinkedList* next;
};

struct LinkedList *newNode(int data) {
	struct LinkedList *new_node = (struct LinkedList *) malloc(
			sizeof(struct LinkedList));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

void insert(struct LinkedList **head, int newData) {
	struct LinkedList *newNode = (struct LinkedList*) malloc(
			sizeof(struct LinkedList));
	newNode->data = newData;
	newNode->next = *head;
	*head = newNode;
}

void reverse(struct LinkedList **head) {
	struct LinkedList *curr = *head;
	struct LinkedList *next;
	struct LinkedList *prev = NULL;

	while (curr != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*head = prev;
}

struct LinkedList* addTwoLists(struct LinkedList *First,struct LinkedList *Second) {
	int sum, carry = 0;
	struct LinkedList* res = NULL; // res is head node of the resultant list
	struct LinkedList *temp, *prev = NULL;

	while (First != NULL || Second != NULL) {
		sum = carry + (First ? First->data : 0) + (Second ? Second->data : 0);
		carry = (sum >= 10) ? 1 : 0;
		sum = sum % 10;
		temp = newNode(sum);
		if (res == NULL)
			res = temp;
		else
			prev->next = temp;

		prev = temp;
		if (First)
			First = First->next;
		if (Second)
			Second = Second->next;
	}

	if (carry > 0)
		temp->next = newNode(carry);
	return res;
}

void print(struct LinkedList *temp) {
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main() {
	struct LinkedList* first = NULL;
	struct LinkedList* second = NULL;
	struct LinkedList* res = NULL;

	// create first list 7->5->9->4->6
	insert(&first, 6);
	insert(&first, 4);
	insert(&first, 9);
	insert(&first, 5);
	insert(&first, 7);
	printf("First List is ");
	print(first);

	// create second list 8->4
	insert(&second, 4);
	insert(&second, 8);
	printf("Second List is ");
	print(second);

	// Add the two lists and see result
	res = addTwoLists(first, second);
	print(res);
	return 0;

}
