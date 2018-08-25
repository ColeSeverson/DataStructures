#include "./binaryTree.h"
#include <stdio.h>

int compare(void * a, void * b){
	int a1 = *(int *)(a);
	int b1 = *(int *)(b);
	return a1 - b1;
}

int main(){

	int array[5] = { 50, 52, 49, 51, 53 };
	binaryTree * bin = new binaryTree();
	bin->setCompareMethod(&compare);
	for(int i = 0; i < 5; i++){
		bin->addNode((void *)(&array[i]));
	}
	bin->printTree();

return 0;
}
