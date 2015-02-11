typedef struct bstree BSTree;
typedef struct node Node;
struct node
{
	int data;
	Node* left;
	Node* right;
};
struct bstree
 {
 	Node* root;
 }; 
BSTree createBSTree(void);