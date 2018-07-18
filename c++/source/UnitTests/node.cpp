#include <stdio.h>

#include "Include/node.h"

int main(){
	node * temp = new node();      //constructed NULL
	node * temp1 = new node(temp); //with just a parent
	
	int data = 100;
	void * ref = (void *)(&data);

	int data2 = 67;
	void * ref2 = (void *)(&data2);

	node * temp2 = new node(ref);
	node * temp3 = new node(ref2, temp2);
	
}
