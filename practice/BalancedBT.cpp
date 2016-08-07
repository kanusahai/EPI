#include<iostream>
#include<cmath>
using namespace std;

struct node {
  int val;
  node* left;
  node* right;
};

class BT {
  private:
  node* root;

  bool isBalanced(node* p) {
    if(p==NULL) 
      return true;

    int heightL=findHeight(p->left);
    int heightR=findHeight(p->right);

    if(abs(heightL-heightR)<=1 && isBalanced(p->right) && isBalanced(p->left)) 
      return true;

    return false;

  }

  int findHeight(node* p) {
    if(p==NULL)
      return -1;

    int htL=findHeight(p->left);
    int htR=findHeight(p->right);
    if(htR>=htL) {
      return htR+1;
    } else {
      return htL+1;
    }
  }
  public:
  BT() {
    root=NULL;
  }

  void setRoot(node* root) {
    this->root=root;
  }

  bool isBalanced() {
    return isBalanced(this->root);
  }

  void insert(int num) {
    node* newNode=new node();
    newNode->val=num;
    newNode->left=NULL;
    newNode->right=NULL;

    if(root==NULL) {
      root=newNode;
      return;
    }
    node* p=root;
    
    while(p!=NULL) {
      if(p->val>num) {
        if(p->left==NULL) {
          p->left=newNode;
          return;
        } else
          p=p->left;
      } else {
        if(p->right==NULL) {
          p->right=newNode;
          return;
        } else {
          p=p->right;
        }
      }
    }
    return;
  }
};

int main() {
  BT bt;
  bt.insert(3);
  bt.insert(2);
  bt.insert(4);

  if(bt.isBalanced())
    cout<<"Yay!\n";
  else
    cout<<"No!\n"; 
  return 0;
}
