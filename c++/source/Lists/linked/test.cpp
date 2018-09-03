#include <stdio.h>

#include "./linked.h"

void print(void * v){
	printf("%d\n", *((int *)(v)));
}

int main(){

	linkedList * ll = new linkedList();
	int array[5] = {1, 5, 3, 4, 6};
	
	for(int i = 0; i < 5; i++)
		ll->push(&(array[i]));

	ll->setPrintMethod(&print);

	ll->print();

return 0;
}
