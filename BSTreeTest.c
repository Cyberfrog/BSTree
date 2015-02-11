#include "expr_assert.h"
#include "BSTree.h"
#include <stdio.h>

void test_createBSTree_creates_tree_with_root_initilize_to_NULL(){
	
	BSTree t = createBSTree();
	assert(t.root==NULL);
}