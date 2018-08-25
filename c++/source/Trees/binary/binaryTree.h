#ifndef BINARYTREE
#define BINARYTREE

#include "../../Include/publicAttributesNode.h"

class binaryTree{
	private:
		int size;
		int (*compare)(void *, void *);
	
	public:
		binaryTree();
		node * head;
		void setCompareMethod(int (*compMethod)(void *, void *)){compare = compMethod;};
		int addNode( void * );
		int findNode( void * );
		int removeNode( void * );
		int printTree();
};

#endif
