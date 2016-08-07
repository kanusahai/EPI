#include<iostream>

using namespace std;

struct node {
	int val;
	node * left;
	node * right;
	int total;
};
class OST {
	private:
	node* root;

	void select(node *p, int* count, int k) {
		if(p==NULL || count==NULL) return;
		select(p->left, count, k);
		*count+=1;
		if(*count==k) {
			cout<<k<<" position number: "<<p->val<<"\n";
			return;
		}
		select(p->right, count, k);
	}

        void printTotals(node *p) {
		if(p==NULL) return;
		printTotals(p->left);
		cout<<" Value at node : "<<p->val<<"  Total at node : "<<p->total<<"\n";
		printTotals(p->right);
	}

	void select(node* p, int k) {
		if(p==NULL || k>p->total) return;

		if((k==1 && p->left==NULL) || (p->left!=NULL && p->left->total==k-1)) {
			cout<<"Value at position : "<<p->val<<"\n";
			return;
		}

		
		if(p->left!=NULL) { 
			if(p->left->total>=k) {
				select(p->left, k);
   				return;
			} else {
				select(p->right, k-p->left->total-1);
			}	
		} else {
			select(p->right, k-1);
		}
		
	}

	public:
	OST() {
		root=NULL;
	}

	void insert(int val) {
		if(root==NULL) {
			root=new node();
			root->val=val;
			root->right=NULL;
			root->left=NULL;
			root->total=1;
			return;
		}
		node* p=root;
		node* q=root;

		while(p!=NULL) {
			while(p!=NULL && p->val>=val) {
				q=p;
				p=p->left;
				q->total+=1;
			}
			while(p!=NULL && p->val<=val) {
				q=p;
				p=p->right;
				q->total+=1;
			}
		}	
		node* newNode=new node();
                newNode->val=val;
                newNode->left=NULL;
                newNode->right=NULL;
		newNode->total=1;

		if(q->val>=val) {
			q->left=newNode;
		} else {
			q->right=newNode;
		}

		return;
	}	

	void select(int k) {
		int* count=new int(0);
		//select(root, count, k);

		//cout<<"Newer efficient method\n";
		select(root, k);
	}

	void printTotals() {
		printTotals(root);
	}
};

int main() {
	OST ost;
	ost.insert(5);
	ost.insert(3);
	ost.insert(2);
	ost.insert(4);
	ost.insert(7);
	ost.insert(6);
	
	//ost.printTotals();
	for(int i=1; i<=6;i++)
		ost.select(i);

	return 0;
}
