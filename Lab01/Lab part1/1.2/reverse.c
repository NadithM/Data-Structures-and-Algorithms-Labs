#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"

char * Reverse(char * array){
	int i;

	size_t len = strlen(array);
	STACK Stack1=(STACK)stackCreate(100);
	for(i = 0; i <len; i++)
		stackPush(Stack1,array[i]);
	for(i = 0; i <len; i++)
		stackPop(Stack1,&(array[i]));
	
	return array;
}



int main (){


	char name[100];
	printf("Enter Your Text? \n");
	fgets(name,100,stdin);
	//printf("%s",name);
	Reverse(name);
	printf("%s",name);


return 0;
}