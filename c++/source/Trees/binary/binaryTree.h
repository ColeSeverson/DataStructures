#ifndef BINARYTREE
#define BINARYTREE

#include "../../Include/publicAttributesNode.h"

class binaryTree{
	private:
		int size;
		int (*compare)(void *, void *);
		node * deleteNode(node *, void *);
	
	public:
		binaryTree():head(NULL){}
		node * head;
		void setCompareMethod(int (*compMethod)(void *, void *)){compare = compMethod;};
		int addNode( void * );
		int findNode( void * );
		int removeNode( void * );
		int printTree();
};

#endif
