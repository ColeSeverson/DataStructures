#ifndef NODE
#define NODE
#include <stdio.h>

class node{
	public:
		void * data;
		node * left;
		node * right;
		node * parent;
	
		//various constructors
		node()			: parent(NULL), data(NULL), left(NULL), right(NULL){};
		node(node * p) 	 	: parent(p), data(NULL), left(NULL), right(NULL){};
		node(void * d)  	: parent(NULL), data(d), left(NULL), right(NULL){};
		node(void * d, node * p): parent(p), data(d), left(NULL), right(NULL){};

/*		int compare( node * n ){
			if(compareMethod == NULL){
				printf("define a function to compare the Nodes please\n"); 
				return -1;
			}else{
				return compareMethod(this->data, n->data);
			}
		}*/

};

#endif
