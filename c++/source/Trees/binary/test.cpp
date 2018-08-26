#include "./binaryTree.h"
#include <stdio.h>

int compare(void * a, void * b){
	int a1 = *(int *)(a);
	int b1 = *(int *)(b);
	return a1 - b1;
}
void print(void * a){
	int a1 = *(int *)(a);
	printf("%d\n", a1);
}
int main(){

	int array[12] = { 50, 52, 49, 51, 53, 26, 71, 64, 65, 63, 12, 100};
	binaryTree * bin = new binaryTree();
	binaryTree * bin2 = new binaryTree();
	bin->setCompareMethod(&compare);
	bin->setPrintMethod(&print);
	bin2->setCompareMethod(&compare);
	bin2->setPrintMethod(&print);
	for(int i = 0; i < 12; i++){
		bin->addNode((void *)(&array[i]));
		bin2->addNode((void *)(&array[i]));
	}

	bin->printTree();
	bin->removeNode((void *)(&array[6]));
	bin->printTree();
	
	printf("Tree 2 -------------\n");
	
	bin2->printTree();
	bin2->removeNode((void *)(&array[0]));
	bin2->printTree();
return 0;
}
