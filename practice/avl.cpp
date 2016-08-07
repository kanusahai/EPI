#include<iostream>

using namespace std;

struct node {
	int val;
	node* right;
	node* left;
	int balance;

	node() {}	
	node(int val) { 
		this->val=val; 
		this->right=NULL;
		this->left=NULL;
		this->balance=0;
	}
};

class AVL {
	private:
	node* root;

	node* rightRotate(node* p) {
		if(p==NULL) return p;
		if(p->right==NULL) return p;

		node* retVal = p->right;

		p->right = retVal->left;
		retVal->left=p;
		return retVal;
	}

	node* leftRotate(node* oldRoot){
		if(oldRoot==NULL) return oldRoot;
		if(oldRoot->left==NULL) return oldRoot;
		
		node* newRoot = oldRoot->left;
		oldRoot->left = newRoot->right;
		newRoot->right = oldRoot;
		return newRoot;		
	}

	void insert(int num, node* p) {
		if(p==NULL) return;

		if(p->val>=num) {
			insert(
		}

	}

	public:
	AVL() {
		root=NULL;
	}

	void insert(int num) {
		if(root==NULL) {
			root=new node(num);
			return;
		}
		node* p=root;
		node* q=p;

		while(p!=NULL) {
			if(q->balance==-1 && p-
			q=p;
			if(p->val>=num) {
				p=p->left;
			} else {
				p=p->right;
			}

		}
	}	
	

};
