#include <stdio.h>
#include <stdlib.h>

#define DATA_TYPE int
typedef struct node node;
typedef node** STACK;

struct node{
DATA_TYPE data;
node * next;

};



STACK stackCreate(){
 STACK temp=malloc(sizeof(node *));
 *temp=NULL;
	return temp;
}

int stackDestroy(STACK top){
	node * head=*top;

	while(head!=NULL){
		head=(*top)->next;
		free(*top);
		*top=head;
	}

	return 1;

}

int StackIsEmpty(STACK top){

	if((*top)==NULL) return 1;


	return 0;
}


int stackPush(STACK top,DATA_TYPE data){

	node * temp=NULL;
	temp=malloc(sizeof(node));
	if(temp==NULL) return 0;
	temp->data=data;
	temp->next=*top;
	*top=temp;
	return 1;
}

int stackPop(STACK top,DATA_TYPE  * data){

	if( StackIsEmpty(top) )
	return 0;
	
	*data=(*top)->data;
	node * temp=*top;
	*top=temp ->next;

	free(temp);
	
	return 1;
}


int stackPeek(STACK top,DATA_TYPE *data){

	if(StackIsEmpty(top))
		return 0;
 	*data= (*top)->data;
	return 1;
}



void stackReverseRec(STACK head) {
  if (!(*head)) return;
  node * rest = (*head)->next;
  if (!rest) return;
 stackReverseRec(&rest);

  (*head)->next->next = (*head);
  (*head)->next = NULL;
  (*head) = rest;
}

void stackReverseIter(STACK head) {
  if (!(*head)) return;
  node * prev = NULL;
  node * curr = *head;
  while (curr) {
    node * next1 = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next1;
  }
  *head = prev;
}

int main(){


STACK Stack = stackCreate();
int data=0,data1=0;
for(data=0;data<50;data++){

if(stackPush(Stack,data))
printf(" Push %i  ",data);
}

/*
 Push 0   Push 1   Push 2   Push 3   Push 4   Push 5   Push 6   Push 7   Push 8   Push 9   Push 10
 Push 11   Push 12   Push 13   Push 14   Push 15   Push 16   Push 17   Push 18   Push 19   Push 20   
 Push 21   Push 22   Push 23   Push 24   Push 25   Push 26   Push 27   Push 28   Push 29   Push 30   
 Push 31   Push 32   Push 33   Push 34   Push 35   Push 36   Push 37   Push 38   Push 39   Push 40   
 Push 41   Push 42   Push 43   Push 44   Push 45   Push 46   Push 47   Push 48   Push 49
 
 */



if(stackPeek(Stack,&data))
printf(" \n peek %i \n",data);
// peek 49


stackReverseRec(Stack);

printf("\n\n");
for(data1=50;data1>0;data1--){

if(stackPop(Stack,&data))
	printf(" pop %i ",data);
}
printf("\n\n");
/*
 after using recursive method
 pop 0  pop 1  pop 2  pop 3  pop 4  pop 5  pop 6  pop 7  pop 8  pop 9  pop 10  
 pop 11  pop 12  pop 13  pop 14  pop 15  pop 16  pop 17  pop 18  pop 19  pop 20  
 pop 21  pop 22  pop 23  pop 24  pop 25  pop 26  pop 27  pop 28  pop 29  pop 30  
 pop 31  pop 32  pop 33  pop 34  pop 35  pop 36  pop 37  pop 38  pop 39  pop 40  
 pop 41  pop 42  pop 43  pop 44  pop 45  pop 46  pop 47  pop 48  pop 49
*/

for(data=50;data<100;data++){

if(stackPush(Stack,data))
printf(" Push %i  ",data);
}

/*
  Push 50   Push 51   Push 52   Push 53   Push 54   Push 55   Push 56   Push 57   Push 58   Push 59   Push 60   
  Push 61   Push 62   Push 63   Push 64   Push 65   Push 66   Push 67   Push 68   Push 69   Push 70   Push 71   
  Push 72   Push 73   Push 74   Push 75   Push 76   Push 77   Push 78   Push 79   Push 80   Push 81   Push 82   
  Push 83   Push 84   Push 85   Push 86   Push 87   Push 88   Push 89   Push 90   Push 91   Push 92   Push 93   
  Push 94   Push 95   Push 96   Push 97   Push 98   Push 99

if we pop it should be like
 pop 99  pop 98  pop 97  pop 96  pop 95  pop 94  pop 93  pop 92  pop 91  pop 90  pop 89  pop 88  pop 87  pop 86  
 pop 85  pop 84  pop 83  pop 82  pop 81  pop 80  pop 79  pop 78  pop 77  pop 76  pop 75  pop 74  pop 73  pop 72  
 pop 71  pop 70  pop 69  pop 68  pop 67  pop 66  pop 65  pop 64  pop 63  pop 62  pop 61  pop 60  pop 59  pop 58  
 pop 57  pop 56  pop 55  pop 54  pop 53  pop 52  pop 51  pop 50
 */


//then we reverse it using iterative method
stackReverseIter(Stack);


printf("\n\n");
for(data1=50;data1>0;data1--){

if(stackPop(Stack,&data))
	printf(" pop %i ",data);
}


/*

now it is....
 pop 50  pop 51  pop 52  pop 53  pop 54  pop 55  pop 56  pop 57  pop 58  pop 59  pop 60  
 pop 61  pop 62  pop 63  pop 64  pop 65  pop 66  pop 67  pop 68  pop 69  pop 70  pop 71  
 pop 72  pop 73  pop 74  pop 75  pop 76  pop 77  pop 78  pop 79  pop 80  pop 81  pop 82  
 pop 83  pop 84  pop 85  pop 86  pop 87  pop 88  pop 89  pop 90  pop 91  pop 92  pop 93  
 pop 94  pop 95  pop 96  pop 97  pop 98  pop 99
 */

/*
for(data=50;data>25;data--){

if(stackPop(Stack,&data))
	printf(" pop %i\n",data);
}

if(stackPeek(Stack,&data))
	printf(" peek %i\n",data);

stackDestroy(Stack);


*/	return 0;
}
