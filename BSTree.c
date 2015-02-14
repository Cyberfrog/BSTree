#include "BSTree.h"
#include <stdio.h>
BSTree createBSTree(){
	return (BSTree){NULL};
}
Node * createNode(int data){
	Node * node = (Node *)calloc(sizeof(Node),1);
	node->data = data;
	return node;
}
Node * findEqual(Node * node,int data){
	if(!node){
		return NULL;
	}
	if(node->data==data){
		return node;
	}
	if(node->data<data && node->right){
		return findEqual(node->right, data);
	}
	if(node->data>data && node->left){
		return findEqual(node->left, data);
	}
	return NULL;
}
Node * find(BSTree tree, int data){
	return findEqual(tree.root,data);	
}
int insert(BSTree * tree, int data){
	Node * newNode = createNode(data);
	tree->root?insertNode(tree->root,newNode):(tree->root= newNode);
	return 1;
}
void insertNode(Node *root,Node *newNode){
	if(root->data <= newNode->data){
		root->right?insertNode(root->right, newNode):(root->right=newNode);			
	}	
	if(root->data > newNode->data){
		root->left?insertNode(root->right, newNode):(root->left=newNode);					
	}
}
