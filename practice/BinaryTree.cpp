#include<iostream>
#include<queue>

using namespace std;

struct node {
  int val;
  node* left;
  node* right;
};
class CompleteBinaryTree {

  private:
  node* root;

  public:
  CompleteBinaryTree() {
    root=NULL;
  }

  void insert(int num) {
    queue<node*> q;
    if(root==NULL) {
      root=new node();
      root->val=num;
      root->right=NULL;
      root->left=NULL;
      return;
    }    
    q.push(root);
    while(!q.empty()) {
      node *temp=q.front();
      q.pop();
      if(temp->left==NULL || temp->right==NULL) {
        node* newNode=new node();
        newNode->val=num;
        newNode->left=NULL;
        newNode->right=NULL;
        if(temp->left==NULL)
          temp->left=newNode;
        else
          temp->right=newNode;
        return;
      } else {
        q.push(temp->left);
        q.push(temp->right);
      }
    }
    return;
  }

  int remove() {
    if(root==NULL)
      return -1;

    queue<node*> q;
    q.push(root);

    while(!q.empty()) {
      node* temp=q.front();
      q.pop();
      if(temp->left!=NULL)
        q.push(temp->left);

      if(temp->right!=NULL)
        q.push(temp->right);

      if(q.empty()) {
        dele


      }
    }
  }
};


int main() {

  return 0;
}
