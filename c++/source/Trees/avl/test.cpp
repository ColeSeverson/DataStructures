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

return 0;
}
