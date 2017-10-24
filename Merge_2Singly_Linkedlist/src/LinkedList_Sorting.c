/*
 ============================================================================
 Name        : LinkedList_Sorting.c
 Author      : Priyadarshini Singh Solanki
 Version     :
 Copyright   : Your copyright notice
 Description : 1.  Merge two sorted linked lists
 *				2.  Merge Sort for Linked Lists
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct LinkedList {
	int data;
	struct LinkedList* next;
};

void insert(struct LinkedList **head, int newdata) {
	struct LinkedList* newNode = (struct LinkedList*) malloc(
			sizeof(struct LinkedList));
	newNode->data = newdata;
	newNode->next = *head;
	*head = newNode;
}

void MoveNode(struct LinkedList** destRef, struct LinkedList** sourceRef) {
	struct LinkedList* newNode = *sourceRef;
	*sourceRef = newNode->next;
	newNode->next = *destRef;
	*destRef = newNode;
}

struct LinkedList *SortedMerge(struct LinkedList *First,struct LinkedList *Second) {
	struct LinkedList dummy;
	struct LinkedList* tail = &dummy;
	dummy.next = NULL;
	while (1) {
		if (First == NULL) {
			tail->next = Second;
			break;
		} else if (Second == NULL) {
			tail->next = First;
			break;
		}
		if (First->data <= Second->data)
			MoveNode(&(tail->next), &First);
		else
			MoveNode(&(tail->next), &Second);
		tail = tail->next;
	}
	return (dummy.next);
}

void print(struct LinkedList *head) {
	while (head) {
		printf("%d ", head->data);
		head = head->next;
	}
}
int main(void) {

	struct LinkedList* res = NULL;
	struct LinkedList* a = NULL;
	struct LinkedList* b = NULL;

	insert(&a, 15);
	insert(&a, 10);
	insert(&a, 5);

	insert(&b, 20);
	insert(&b, 3);
	insert(&b, 2);

	res = SortedMerge(a, b);
	print(res);

	return 0;
}
