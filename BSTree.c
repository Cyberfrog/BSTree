#include "BSTree.h"
#include <stdio.h>
BSTree createBSTree(){
	return (BSTree){NULL};
}
Node * createNode(int data){
	Node * node = calloc(sizeof(Node),1);
	node->data = data;
	return node;
}