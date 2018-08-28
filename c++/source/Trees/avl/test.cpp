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

	int array[5] = {5, 6, 3, 2, 4};
	for(int i = 0; i < 5; i ++){
		avl->addNode(&(array[i]));
	}
	avl->printTree();
	
return 0;
}
