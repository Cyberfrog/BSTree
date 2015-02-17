typedef struct bstree BSTree;
typedef struct node Node;
typedef void (Traverser)(int);
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
Node * findEqual(Node * node,int data);
int insert(BSTree *, int);
void insertNode(Node *root,Node *newNode);
void traverse(BSTree *,Traverser* t);
void forEachNode(Node *root,Traverser* t);
Node * delete(BSTree *, int);
int findMax(Node *);


