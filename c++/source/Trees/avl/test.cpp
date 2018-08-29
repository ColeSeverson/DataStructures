#include "./avlTree.h"
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
	avlTree * avl = new avlTree();
	avl->setCompareMethod(compare);
	avl->setPrintMethod(print);

	int array[16] = {5, 6, 3, 2, 4, 10, 12, 11, 13, 34, 54, 55, 0, -1, -4, -100};
	for(int i = 0; i < 16; i ++){
		avl->addNode(&(array[i]));
	}
	avl->printTree();
	
return 0;
}
