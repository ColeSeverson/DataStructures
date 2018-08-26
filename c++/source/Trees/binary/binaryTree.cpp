#include <stdio.h>
#include <iostream>
#include <iomanip>

#include "./binaryTree.h"
void removeChildren(node * current){
	if(current->left != NULL)
		removeChildren(current->left);
	if(current->right != NULL)
		removeChildren(current->right);
	delete(current);
}
binaryTree::~binaryTree(){
	if(head != NULL)
		removeChildren(head);
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
node * findSmallestChild(node * in){//used to find the smallest child of a node// just following the left path
	node * current = in;
	while(current->left != NULL)
		current = current->left;
	return current;
}
node * binaryTree::deleteNode(node * current, void * key){
	if(current == NULL)//if the node doesnt exist
		return NULL;
	int dif = compare(key, current->data);//compare the node using given compare method
	if(dif < 0)
		current->left = deleteNode(current->left, key);
	else if(dif > 0)
		current->right = deleteNode(current->right, key);
	else{
		if(current->left == NULL){//if it has found the node to be removed it will test if there is one child or not
			node * temp = current->right;
			delete(current);
			return temp;
		}else if (current->right == NULL){
			node * temp = current->left;
			delete(current);
			return temp;
		}//if there is two children we find the inorder succesor to the right child and that will replace this node
		node * temp = findSmallestChild(current->right);
		current->data = temp->data;
		current->right = deleteNode(current->right, temp->data);
	}
}
int binaryTree::removeNode( void * toDelete){//a precursor method so that programs dont have to include the Node * construct
	if(findNode(toDelete) == 0){
		deleteNode(head, toDelete);
	}else{
		printf("Node not found for delete with signature %p", toDelete);
	}
}

void binaryTree::recursivePrint(node * current, int depth){//prints the left side first then the right side.
	if(!current)
		return;
	recursivePrint(current->left, depth+4);
	
	std::cout << std::setw(depth) << ' ';
	print(current->data);	

	recursivePrint(current->right, depth+4);
}
int binaryTree::printTree(){
	if(print == NULL){
		printf("Please use setPrintMethod(void method(void *)) to set a print method for your datatype including newline\n");
	}
	recursivePrint(head, 0);
}
