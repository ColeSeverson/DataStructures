#include <stdio.h>
#include <iostream>
#include <iomanip>

#include "../../Include/node.h"

class binaryTree{
	
	private:
		int size;
		int (*compare)(void*, void*);
		void (*print)(void *);
		node * head;
		void removeChildren(node * current){//support method for the destructor used to delete all children recursivley
			if(current->left != NULL)
				removeChildren(current->left);
			if(current->right != NULL)
				removeChildren(current->right);
			delete(current);
		}
		node * findSmallestChild(node * in){//used to find the smallest child of a node// just following the left path
			node * current = in;
			while(current->left != NULL)
				current = current->left;
			return current;
		}
		void recursivePrint(node * current, int depth){//prints the left side first then the right side.
			if(!current)
				return;
			recursivePrint(current->left, depth+4);
			
			std::cout << std::setw(depth) << ' ';
			print(current->data);	

			recursivePrint(current->right, depth+4);
		}
		node * deleteNode(node * current, void * key){
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

	public:
	~binaryTree(){//destructor
		if(head != NULL)
			removeChildren(head);
	}
	binaryTree():head(NULL){}
        binaryTree(int (*compareMethod)(void *, void *), void (*printMethod)(void*)){compare = compareMethod; print = printMethod;};
	void setCompareMethod(int (*compMethod)(void *, void *)){compare = compMethod;};
	void setPrintMethod(void (*printMethodInput)(void *)){print = printMethodInput;};

	int addNode( void * in ){
		node * toAdd = new node(in);//first we make a new node for the data given to us

		if (head == NULL){//if there is no head than the node becomes the head
			head = toAdd;
			return 0; //success
		}			
		node * current = head;
		node * previous = NULL;
		while(current != NULL){//previous is used to keep track of the parent 
			previous = current;
			if (compare(toAdd->data, current->data) > 0){//loop through to find where it fits
				current = current->right;
			}else{
				current = current->left;
			}

		}

		toAdd->parent = previous;
		if (compare(toAdd->data, previous->data) > 0){//put it as the left or right tree
			previous->right = toAdd;
			return 0;
		}else{
			previous->left = toAdd;
			return 0;
		}
	};
	int findNode( void * toFind){//returns 0 if the node is present, 1 otherwise
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
	};
	int removeNode( void * toDelete){//a precursor method so that programs dont have to include the Node * construct
		if(findNode(toDelete) == 0){
			deleteNode(head, toDelete);
		}else{
			printf("Node not found for delete with signature %p", toDelete);
		}
	};

	int printTree(){
		if(print == NULL){
			printf("Please use setPrintMethod(void method(void *)) to set a print method for your datatype including newline\n");
		}
		recursivePrint(head, 0);
	};
};
