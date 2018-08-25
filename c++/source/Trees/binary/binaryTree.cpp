#include <stdio.h>
#include <iostream>
#include <iomanip>

#include "./binaryTree.h"

int binaryTree::addNode( void * in ){
	node * toAdd = new node(in);

	if (head == NULL){
		head = toAdd;
		return 0; //success
	}			
	node * current = head;
	node * previous = NULL;
	while(current != NULL){
		previous = current;
		if (compare(toAdd->data, current->data) > 0){
			current = current->right;
		}else{
			current = current->left;
		}

	}

	toAdd->parent = previous;
	if (compare(toAdd->data, previous->data) > 0){
		previous->right = toAdd;
		return 0;
	}else{
		previous->left = toAdd;
		return 0;
	}
}
int binaryTree::findNode( void * ){//returns 0 if the node is present, 1 otherwise
	
}
int binaryTree::removeNode( void * ){}
void print(node * current, int depth){
	if(!current)
		return;
	print(current->left, depth+4);
	
	std::cout << std::setw(depth) << ' ';
	printf("%d\n", *(int *)(current->data));

	print(current->right, depth+4);
}
int binaryTree::printTree(){
	print(head, 0);
}
