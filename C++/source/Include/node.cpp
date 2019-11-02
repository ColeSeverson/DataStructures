#include "node.h"

/*
* Written by Cole Severson
* A class to be used with all data structures that use nodes (trees/lists etc)
*/

node::node(void * dat, node * par, node * nxt1, node * nxt2, int colr){
	data = dat;
	parent = par;
	next1 = nxt1;
	next2 = nxt2;
	color = colr;
}

void * getData(){
	return data;
}

node * getParent(){
	return parent;
}
node * getNext(){
	return next1;
}
node * getLeft(){//will be the same as get Next... Just for clarity when using a tree
	return next1;
}
node * getRight(){
	return next2;
}
int getColor(){
	return color;
}

