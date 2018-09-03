#include "../../Include/node.h"


class linkedList {

	private:
		node * head;
		void (*printNode) (void *);

	public:
		int push(void * toAdd){
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
		void setPrintMethod(void (*printMethod)(void *)){
			printNode = printMethod;
		}
		void print(){
			node * current = head;
			while(current != NULL){
				printNode(current->data);
				current = current->next;
			}
		}


};
