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
int binaryTree::findNode( void * toFind){//returns 0 if the node is present, 1 otherwise
	node * current = head;
	while(current != NULL){
		int dif = compare(toFind, current->data);
		if(dif == 0)
			return 0; //success
		else if (dif > 0){
			current = current->right;
		}else{
			current = current->left;
		}
	}
	return 1; //failed	
}
node * binaryTree::deleteNode(node * current, void * key){
	if(current == NULL)
		return NULL;
	int dif = compare(key, current->data);
	if(dif < 1)
		current->left = deleteNode(current->left, key);
	else if(dif > 0)
		current->right = deleteNode(current->right, key);
	else{
		if(current->left == NULL){
			node * temp = current->right;
			delete(current);
			return temp;
		}else if (current->right == NULL){
			node * temp = current->left;
			delete(current);
			return temp;
		}
	}
}
int binaryTree::removeNode( void * toDelete){
	if (deleteNode(head, toDelete) != NULL)
		return 0;
	else 
		return 1;
}

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
