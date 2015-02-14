#include "expr_assert.h"
#include "BSTree.h"
#include <stdio.h>

BSTree t;
Node *n1,*n2,*n3,*n4,*n5;
void setup(){
	 t = createBSTree();
	n1=createNode(1);
	n2=createNode(2);
	n3=createNode(3);
	n4=createNode(4);
	n5=createNode(5);
	t.root =n3;
	n3->right=n4;
	n4->right=n5;
	n3->left=n2;
	n2->left=n1;
}
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
void test_findEqual_return_node_which_has_equal_value_to_key(){
	Node * result;
	result = findEqual(n3,1);
	assertEqual(result->data,1);
	assert(result->left==NULL);
	assert(result->right==NULL);
}
void test_findEqual_return_NULL_if_key_is_not_found(){
	Node * result;
	result = findEqual(n3,7);
	assert(result==NULL);
}

void test_find_return_node_which_matches_to_key_value(){
	Node * result;
	result = find(t,5);
	assertEqual(result->data,5);
	assert(result->left==NULL);
	assert(result->right==NULL);
}
void test_find_return_NULL_matche_notFound_to_key_value(){
	Node * result;
	result = find(t,5);
	assertEqual(result->data,5);
	assert(result->left==NULL);
	assert(result->right==NULL);
}
void test_insert_inserts_the_data_in_bstree(){
	int result = insert(&t,8);
	Node *r = find(t,8);
	assertEqual(r->data,8);
	assertEqual(result,1);
}
void test_insert_inserts_the_data_in_bstree_at_root_for_first_insert(){
	BSTree tree =createBSTree();
	int result = insert(&tree,8);
	Node *r = find(tree,8); 
	assertEqual(r->data,8);
	assertEqual(result,1);
}
void test_insertNode_inserts_the_newNode_to_right_for_greter_than_equal_vlaues(){
	Node * node1= createNode(5);
	Node * node2=createNode(7);
	insertNode(node1,node2);
	assertEqual(node1->right->data,7);
}
void test_insert_inserts_the_data_to_left_for_less_than_vlaues(){
	BSTree tree =createBSTree();
	int result = insert(&tree,8);
	Node * r;
	insert(&tree, 5);
	assertEqual(tree.root->left->data,5);
	r = find(tree,5); 
	assertEqual(r->data,5);
}