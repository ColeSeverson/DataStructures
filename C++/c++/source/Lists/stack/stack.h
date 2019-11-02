#ifndef STACK
#define STACK

#include "../../Include/node.h"


class stack {

	private:
		node * head;
		void (*printNode) (void *);

	public:
		int push(void * toAdd){//Pushes node into the linked List
			node * temp = new node(toAdd);

			if(head == NULL){
				head = temp;
				return 0;
			}
	
			node * current = head;
			node * previous = NULL;
			while(current != NULL){
				previous = current;
				current = current->next;
			}
			previous->next = temp;
			return 0;
		};
		void * pop(){
			if(head == NULL)
				return NULL;
			
			node * temp = head;
			head = temp->next;
			void * toReturn = temp->data;
			delete temp;
			return toReturn;
		};
		void setPrintMethod(void (*printMethod)(void *)){
			printNode = printMethod;
		};
		void print(){
			node * current = head;
			while(current != NULL){
				printNode(current->data);
				current = current->next;
			}
		};


};
#endif
