#ifndef BINARYTREE
#define BINARYTREE

#include "../../Include/publicAttributesNode.h"

class binaryTree{
	private:
		int size;
		void recursivePrint(node *, int);
		int (*compare)(void *, void *);
		void (*print)(void *);
		node * deleteNode(node *, void *);
	
	public:
		binaryTree():head(NULL){}
		node * head;
		void setCompareMethod(int (*compMethod)(void *, void *)){compare = compMethod;};
		void setPrintMethod(void (*printMethodInput)(void *)){print = printMethodInput;};
		int addNode( void * );
		int findNode( void * );
		int removeNode( void * );
		int printTree();
};

#endif