#include <iostream>
using namespace std;

struct node {
	int value;
	node* left;
	node* right;
};

void inorder(node *root, int *k, node **result, int K) {
	if(root==NULL)
		return;
		
	inorder(root->left, k, result, K);
	*k+=1;
	if(*k==K) {
		*result=root;
		return;
	}
	inorder(root->right, k, result, K);
}
node* findKthSmallest(node* root, int K) {
	node **result = new node*();
	int *k=new int(0);
	
	inorder(root,k,result,K);	
	return *result;
}

int main() {
	node *root = new node();
	root->left=new node();
	root->left->value=1;
	root->left->left=NULL;
	root->left->right=NULL;
	root->value=2;
	root->right=new node();
	root->right->value=3;
        root->right->left=NULL;
        root->right->right=NULL;

	node *kthNode=findKthSmallest(root, 2);
	
	if(kthNode!=NULL) {
		cout<<kthNode->value<<"\n";
	}
	return 0;
}
