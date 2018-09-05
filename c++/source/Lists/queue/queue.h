#include "../../Include/node.h"


class queue {

	private:
		node * head;
		node * tail;
		void (*printNode) (void *);

	public:
		int push(void * toAdd){//Pushes node into the linked List
			node * temp = new node(toAdd);
				
			if(head == NULL){
				head = temp;
				tail = temp;
				return 0;
			}
			node * current = head;
			while(current->next != NULL)
				current = current->next;

			temp->parent = current;
			current->next = temp;

			return 0;
		};
		void * pop(){
			if(tail == NULL)
				return NULL;
			else{
				node * current = tail;
				tail = current->parent;

				void * toReturn = current->data;
				delete current;
				return toReturn;
			}	
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
