#include "expr_assert.h"
#include "BSTree.h"
#include <stdio.h>

void test_createBSTree_creates_tree_with_root_initilize_to_NULL(){
	
	BSTree t = createBSTree();
	assert(t.root==NULL);
}
void test_createNode_creates_node_with_givenData_and_left_right_initilize_to_NULL(){
	Node *n=createNode(5);
	assertEqual(n->data,5);
	assert(n->left==NULL);
	assert(n->right==NULL);
}