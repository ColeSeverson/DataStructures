#ifndef NODE
#define NODE
/*
* Written by Cole Severson
* A class to be used with all data structures that use nodes (trees/lists etc)
*/


class node
{
	private:
		void* data; 
		node * parent;
		node * next1;
		node * next2;
		int color; //for RB tree
	public:
		node(void * dat, node * par, node * nxt1, node * nxt2, int colr);
		void * getData();
		node * getParent();
		node * getNext();
		node * getLeft();//will be the same as get Next... Just for clarity when using a tree
		node * getRight();
		int getColor();
}

#endif
