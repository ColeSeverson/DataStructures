#include <stdio.h>

#include "Trees/binaryTree.h"

int binarytree::addNode( node * toAdd ){
	if (head == NULL){
		head toAdd;
		return 0; //success
	}			
	node * current = head;
	node * previous = NULL;
	while(current->NULL){
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
	}else{
		previous->left = toAdd;
	}
}
int findNode( node * );
int removeNode( void * );
int printTree(node * current, int depth=0){
	if(current!=NULL){
		if(current->left)
			printTree(current->left, depth+4);
		if(current->right)
			printTree(current->right, depth+4);
		if(depth)
			std::cout << std::setw(depth) << ' ';
		printf("%d\n", (int *)(current->data));
	}
}
