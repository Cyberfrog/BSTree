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
Node* createNode(int);
Node * find(BSTree, int);
