#ifndef BINARYTREE
#define BINARYTREE

#include "Include/publicAttributeNode.h"

class binaryTree{
	private:
		node * head;
		int size;
		int (*compare)(void *, void *);
	
	public:
		void setCompareMethod(int (*compMethod)(void *, void *)){compare = compMethod};
		int addNode( node * );
		int findNode( node * );
		int removeNode( void * );
		int printTree();
}

#endif
