#include <stdio.h>
#include <iostream>
#include <iomanip>

#include "./binaryTree.h"

binaryTree::binaryTree():head(NULL){
}
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
		if (compare(toAdd, current) > 0){
			current = current->right;
		}else{
			current = current->left;
		}

	}

	toAdd->parent = previous;
	if (compare(toAdd, previous) > 0){
		previous->right = toAdd;
		return 0;
	}else{
		previous->left = toAdd;
		return 0;
	}
}
int binaryTree::findNode( void * ){}
int binaryTree::removeNode( void * ){}
int print(node * current, int depth){
	if(current!=NULL){
		if(current->left)
			print(current->left, depth+4);
		if(depth)
			std::cout << std::setw(depth) << ' ';
		printf("%d\n", *(int *)(current->data));
		if(current->right)
			print(current->right, depth+4);
	}
}
int binaryTree::printTree(){
	print(head, 0);
}
