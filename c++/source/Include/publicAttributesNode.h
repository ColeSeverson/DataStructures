#ifndef NODE
#define NODE

class node{
	public:
		void * data;
		node * left = NULL;
		node * right = NULL;
		node * parent;
	
		//various constructors
		node()			: parent(NULL), data(NULL){};
		node(node * p) 	 	: parent(p), data(NULL){};
		node(void * d)  	: parent(NULL), data(d){};
		node(void * d, node * p): parent(p), data(d){};

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
