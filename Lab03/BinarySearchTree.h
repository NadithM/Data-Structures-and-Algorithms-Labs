#include <stdio.h>
#include <stdlib.h>


typedef struct node_bst {
	int data;
	struct node_bst *left;
	struct node_bst *right;
} BST_Node;

typedef struct bst {
	BST_Node * root;
} BST_R;

typedef BST_R * BinarySearchTree;
typedef BST_Node * BNodeP;

BinarySearchTree createBST(void)
{
	BinarySearchTree tree = (BinarySearchTree) malloc(sizeof(BST_R));
	tree->root = NULL;
	return tree;
}

void deleteNode(BNodeP p)
{
	if(p->left != NULL)
		deleteNode(p->left);
	if(p->right != NULL)
		deleteNode(p->right);
	free(p);
}

int destroyBST(BinarySearchTree tree)
{
	if(tree->root != NULL)
		deleteNode(tree->root);
	free(tree);
	return 0;
}

int addNode(BNodeP p, int data)
{
	if(data < (p->data)){
		if(p->left != NULL)
			addNode(p->left, data);
		else{
			BNodeP node = (BNodeP) malloc(sizeof(BST_Node));
			node->right = NULL;
			node->left = NULL;
			node->data = data;
			p->left = node;
		}

	}
	else{
		
		if(p->right != NULL)
			addNode(p->right, data);
		else{
			BNodeP node = (BNodeP) malloc(sizeof(BST_Node));
			node->right = NULL;
			node->left = NULL;
			node->data = data;
			p->right = node;
		}
	}
	return 0;
}

int addBST(BinarySearchTree tree, int data)
{
	if(tree->root != NULL)
		addNode(tree->root, data);
	else{
		BNodeP node = (BNodeP) malloc(sizeof(BST_Node));
		node->left = NULL;
		node->right = NULL;
		node->data = data;
		tree->root = node;
	}
	return 0;
}

BNodeP copyNode(BNodeP src)
{
	BNodeP node = (BNodeP)malloc(sizeof(BST_Node));
	node->data = src->data;
	if(src->right != NULL)
		node->right = copyNode(src->right);
	else
		node->right = NULL;
	if(src->left != NULL)
		node->left = copyNode(src->left);
	else
		node->left = NULL;
	
	return node;
}

BinarySearchTree copyBST(BinarySearchTree tree)
{
	BinarySearchTree copy = createBST();
	if(tree->root != NULL)
		copy->root = copyNode(tree->root);
	return copy;
}

BNodeP findRec(BNodeP p, int data){
	if(data == p->data)
		return p;
	if((data < p->data) && (p->left != NULL)){
		return findRec(p->left, data);
	}
	else if(p->right != NULL)
		return findRec(p->right, data);
	return NULL;
}

BNodeP findBST(BinarySearchTree tree, int data){
	if(tree->root != NULL)
		return findRec(tree->root, data);
	return NULL;
	
}


int findMinRec(BNodeP p){
	if(p->left != NULL)
		return findMinRec(p->left);
	return p->data;
}

int findMin(BinarySearchTree tree){
	int min;
	if(tree->root != NULL){
		min = findMinRec(tree->root);
		return min;
	}
	return (int)NULL;
}


int findMaxRec(BNodeP p){
	if(p->right != NULL)
		return findMaxRec(p->right);
	return p->data;
}

int findMax(BinarySearchTree tree){
	int max;
	if(tree->root != NULL){
		max = findMaxRec(tree->root);
		return max;
	}
	return (int)NULL;
}

BNodeP findHOF(BNodeP p){
	if(p->left->left != NULL)
		return findHOF(p->left);
	return p;
}

BNodeP findHOP(BNodeP p){
	if(p->right->right != NULL)
		return findHOP(p->right);
	return p;
}

int deleteTheNode(BNodeP par, int data){
	BNodeP node = NULL;
	if(data <= par->data){
		node = par->left;
		if((node->left == NULL) && (node->right == NULL)){		
			free(node);
			par->left = NULL;
			return 0;
		}
		
		if(node->right == NULL){
			par->left = node->left;
			free(node);
			return 0;
		}
		if(node->left == NULL){
			par->left = node->right;
			free(node);
			return 0;
		}
	}
	else{	
		node = par->right;
		if((node->left == NULL) && (node->right == NULL)){		
			free(node);
			par->right = NULL;
			return 0;
		}
		
		if(node->right == NULL){
			par->right = node->left;
			free(node);
			return 0;
		}
		if(node->left == NULL){
			par->right = node->right;
			free(node);
			return 0;
		}
	}

	char dir = rand() % 2;
	if(dir == 0){
		if(node->right->left == NULL){ 
			node->data = node->right->data;
			free(node->right);
			node->right = NULL;
		}
		else{
			BNodeP headOfSuccessor = findHOF(node->right);
			node->data = headOfSuccessor->left->data;
			deleteTheNode(headOfSuccessor, node->data);
		}
	}
	else{
		if(node->left->right == NULL){ 
			node->data = node->left->data;
			free(node->left);
			node->left = NULL;
		}
		else{
			BNodeP headOfPredecessor = findHOP(node->left);
			node->data = headOfPredecessor->right->data;
			deleteTheNode(headOfPredecessor, node->data);
		}
	}
	return 0;
}

BNodeP findTheParent(BNodeP par, int data){	
	if((data <= par->data) && (par->left != NULL)){
		if(par->left->data == data)
			return par;
		return findTheParent(par->left, data);
	}
	if((data > par->data) && (par->right != NULL)){
		if(par->right->data == data)
			return par;
		return findTheParent(par->right, data);
	}
	return NULL;
}

int deleteBST(BinarySearchTree tree, int data){
	if(tree->root != NULL){
		if (data == tree->root->data){
			BNodeP node = (BNodeP)malloc(sizeof(BST_Node));
			node->data = tree->root->data;
			node->left = tree->root;
			node->right = NULL;
			tree->root = node;
			BNodeP par = findTheParent(tree->root, data);
			if(par != NULL)
				deleteTheNode(par, data);
			node = tree->root;
			tree->root = node->left;
			free(node);
		}
		else{
			BNodeP par = findTheParent(tree->root, data);
			if(par != NULL)
				deleteTheNode(par, data);
		}
	}
	return 0;
}

void printRec(BNodeP p){
	if(p->left != NULL)
		printRec(p->left);
	printf("%d ", p->data);
	if(p->right != NULL)
		printRec(p->right);	
}

void printOrderedList(BinarySearchTree tree){
	printf("The ordered list Ascending = { ");
	if(tree->root != NULL)
		printRec(tree->root);
	printf("}\n");
}
