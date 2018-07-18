#ifndef BINARYTREE
#define BINARYTREE

#include "Include/publicAttributesNode.h"

class binaryTree{
	private:
		int size;
		int (*compare)(void *, void *);
	
	public:
		node * head;
		void setCompareMethod(int (*compMethod)(void *, void *)){compare = compMethod;};
		int addNode( node * );
		int findNode( node * );
		int removeNode( void * );
		int printTree(node *, int);
};

#endif
