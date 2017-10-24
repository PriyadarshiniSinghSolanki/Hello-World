/*
 * trybst.c
 *
 *  Created on: 18-Jul-2017
 *      Author: Sys-5304
 */

#include <stdio.h>
#include <stdlib.h>
struct BST {
	int data;
	struct BST *left, *right;
};

struct BST *insert(int key) {
	struct BST* newnode = (struct BST*) malloc(sizeof(struct BST));
	newnode->data = key;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

struct BST* push(struct BST* node, int key) {

	if (node == NULL)
		return insert(key);
	if (node->data < key)
		node->right = push(node->right, key);
	else if (node->data > key)
		node->left = push(node->left, key);
	return node;
}

void print(struct BST* root) {
	if (root != NULL) {
		print(root->left);
		printf("%d \n", root->data);
		print(root->right);
	}
}

int main() {
	struct BST* root = NULL;
	root = push(root, 5);
	push(root, 3);
	push(root, 2);
	push(root, 1);
	push(root, 5);
	push(root, 4);
	push(root, 6);
	push(root, 7);
	print(root);

	return 0;
}
