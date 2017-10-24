/*
 ============================================================================
 Name        : LinkedList.c
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

void PrintList(struct LinkList *n){
	while(n != NULL){
		printf("\n%d", n->data);
		n = n->next;
	}
}
int main(void) {
	struct LinkList *Head = NULL;
	struct LinkList *Second = NULL;
	struct LinkList *Third = NULL;

	// allocate 3 nodes in the heap
	Head = (struct LinkList*) malloc(sizeof(struct LinkList));
	Second = (struct LinkList*) malloc(sizeof(struct LinkList));
	Third = (struct LinkList*) malloc(sizeof(struct LinkList));

	Head->data = 1;
	Head->next = Second;

	Second->data = 2;
	Second->next = Third;

	Third->data = 3;
	Third->next = NULL;

	PrintList(Head);
	return EXIT_SUCCESS;
}
