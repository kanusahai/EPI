#include<iostream>
#include<string>
using namespace std;

struct node {
	int val;
	node* left;
	node* right;

	node(int val) {
		this->val=val;
		this->left=NULL;
		this->right=NULL;
	}
};

class BT {
	private:
	node* root;

	void printTree(node* p) {
		if(p==NULL) return;
		printTree(p->left);
		cout<<p->val<<" ";
		printTree(p->right);
	}

	public:
	BT() {

	}

	BT(string inorder, string preorder) {
		root=computeTree(inorder, preorder);
	}

	node* computeTree(string inorder, string preorder) {
		if(inorder.length()!=preorder.length()) return NULL;

		if(inorder.length()==0) return NULL;

		int i;
		for(i=0;i<inorder.length();i++) {
			if(inorder[i]==preorder[0])
				break;
		}

		node* newRoot=new node(preorder[0]-'A');
		if(i-1>=0) {
			string newIO(inorder,0,i);
			string newPO(preorder,1,i);
			newRoot->left=computeTree(newIO, newPO);
		}

		if(i+1<inorder.length()) {
			string newIO(inorder,i+1,inorder.length()-i-1);
			string newPO(preorder, i+1, preorder.length()-i-1);
			newRoot->right=computeTree(newIO, newPO);
		}
		return newRoot;
	}

	void printTree() {
		printTree(root);
		cout<<"\n";
	}
};

int main() {
	BT bt("FBAEHCDIG", "HBFEACDGI");
	bt.printTree();
	return 0;
}
