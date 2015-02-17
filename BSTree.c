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

void traverse(BSTree *tree,Traverser *t){
	forEachNode(tree->root, t);
}
void forEachNode(Node *root,Traverser *t){
	if(!root){return ;}
	if(root->left){
		forEachNode(root->left, t);
	}
	t(root->data);
	if(root->right){
		forEachNode(root->right,t);
	}
}

Node * delete(BSTree *tree, int data){
	Node * node;
	if(tree->root->data == data){
		node = tree->root;
		tree->root =NULL;
		return node;
	}
	return	deleteNode(tree->root,data);
}

Node * deleteNode(Node *node, int data){
	int max;
	Node * deleted =NULL;
	
	if(hasChiled(node)){
		if(node->data ==data){
			max =findMax(node->left);
			node->data = max;
			deleted =deleteNode(node->left,max);
			deleted->data=max;
			return deleted;
		}
	}
	if(hasLeftChiled(node)){
		if(node->left->data ==data){
			deleted = node->left;

			if(hasLeftChiled(node->left)){
				node->left = node->left->left;
			}
			if(hasRightChiled(node->left)){
				node->left = node->left->right;
			}
		}
	}
	if(hasRightChiled(node)){
		deleted = node->right;
		if(node->right->data ==data){
			if(hasLeftChiled(node->right)){
				node->right = node->right->left;
			}
			if(hasRightChiled(node->left)){
				node->right = node->right->right;
			}
		}
	}
	return deleted;
}
int hasChiled(Node *node){
	return (node->left || node->right)&&1;
}
int hasLeftChiled(Node *node){
	return node->left && 1;
}
int hasRightChiled(Node *node){
	return node->right && 1;
}

int findMax(Node *node){
	int rightmax=0,leftMax=0,max=0;
	if(node->right){
		rightmax =findMax(node->right);
	}
	if(node->left){
		leftMax =findMax(node->left);
	}
	max = rightmax>=leftMax?rightmax:leftMax;
	return max>=node->data?max:node->data;
}
