#ifndef NODE
#define NODE

class node{
	private:
		void * data;
		node * left = NULL;
		node * right = NULL;
		node * parent;
	public:
		//various constructors
		node()			: parent(NULL), data(NULL){};
		node(node * p) 	 	: parent(p), data(NULL){};
		node(void * d)  	: parent(NULL), data(d){};
		node(void * d, node * p): parent(p), data(d){};

		void * getData(){ return data; };
		node * getLeft(){ return left; };
		node * getRight(){ return right; };
		node * getNext(){ return left; };
		node * getParent(){ return parent; };
	/*	int compare( node * n ){
			if(compareNode == NULL){
				printf("define a function to compare the Nodes please\n"); 
				return -1;
			}else{
			return compareNode(this->data, n->getData());
			}
		}*/

		void setData( void * dat ){ data = dat; };
		void setLeft( node * lef ){ left = lef; };
		void setRight( node * righ ){ right = righ; };
		void setNext( node * nex ){ left = nex; }; 
		void setParent( node* par ){ parent = par; };
};

#endif
