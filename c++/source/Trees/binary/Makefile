binary: binaryTree.o
	g++ -g -o test  test.cpp binaryTree.o
binaryTree.o: binaryTree.h binaryTree.cpp
	g++ -g -c binaryTree.cpp 
clean:
	rm *.o test
