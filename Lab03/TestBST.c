#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"

#define SIZE 20

int main(void)
{

	BinarySearchTree tree1 = createBST();
	int i=0;
	int array[SIZE];

	for(i=0;i<SIZE;i++){

		array[i]=rand() % 100;
		addBST(tree1,array[i]);

	}

	printf("%s\n\n","Print the Tree1 Created");
	printOrderedList(tree1);

	int max =findMax(tree1);

	int min= findMin(tree1);

	printf("MAX: %d  and MIN %d \n\n",max,min );
	

	BinarySearchTree tree2 = copyBST(tree1);

	printf("%s\n\n","Copied all the Elements in Tree1 to Tree2" );
	
	printf("%s\n\n","Print the Tree2 Copied from tree1");
	
	printOrderedList(tree2);

	printf("%s\n\n","Deleting random Element from tree2");
	
	deleteBST(tree2, array[SIZE-rand()%SIZE]);

	printf("%s\n\n","Print the Tree2 ");
	
	printOrderedList(tree2);

	printf("%s\n\n","Deleting several random Element from tree2");
	
	deleteBST(tree2,array[SIZE-rand()%SIZE]);
	deleteBST(tree2, array[SIZE-rand()%SIZE]);
	deleteBST(tree2, array[SIZE-rand()%SIZE]);
	deleteBST(tree2, array[SIZE-rand()%SIZE]);
	deleteBST(tree2, array[SIZE-rand()%SIZE]);
	deleteBST(tree2, array[SIZE-rand()%SIZE]);
	deleteBST(tree2, array[SIZE-rand()%SIZE]);
	deleteBST(tree2, array[SIZE-rand()%SIZE]);

	printf("%s\n\n","Print the Tree2 ");
	
	printOrderedList(tree2);

	printf("%s\n\n","Distroing the tree1 and Tree2 ");
	

	destroyBST(tree1);
	destroyBST(tree2);
	return 0;
}