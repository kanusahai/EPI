#include<iostream>
#include<queue>
using namespace std;

struct node {
  int value;
  node* right;
  node* left;
};

class BinaryTree {

  private:
  node* root;

  public:
  BinaryTree() {
    root=NULL;
  }

  void printLeftView() {
    if(root==NULL)
      return;
    queue<node*> buffer;
    
    int numOfNodesOnCurrentLevel=1;
    int numOfNodesOnNextLevel=0;
    bool shouldPrint=true;
    buffer.push(root);
    node* temp=NULL;
    while(buffer.size()!=0) {
      temp=buffer.front(); 
      if(shouldPrint) {
        cout<<temp->value<<" ";
        shouldPrint=false;
      }
      
      if(temp->left!=NULL) {
        buffer.push(temp->left);
        numOfNodesOnNextLevel+=1;
      } 
      if(temp->right!=NULL) {
        buffer.push(temp->right);
        numOfNodesOnNextLevel+=1; 
      }
      
      buffer.pop();
      numOfNodesOnCurrentLevel-=1;
      if(numOfNodesOnCurrentLevel==0) {
        numOfNodesOnCurrentLevel=numOfNodesOnNextLevel;
        numOfNodesOnNextLevel=0;
        shouldPrint=true;
      }

    }
    
  }

  void buildMockTree() {
    root=new node();
    root->value=2;
    root->left=new node();
    root->left->value=3;
    root->left->left=NULL;
    root->left->right=NULL;

    //Right subtree
    node* subroot=new node();
    subroot->value=4;
    subroot->right=new node();
    subroot->left=new node();
    subroot->right->value=5;
    subroot->right->right=NULL;
    subroot->right->left=NULL;
    subroot->left->value=6;
    subroot->left->right=NULL;
    subroot->left->left=NULL;
    
    root->right=subroot;

  }
};

int main() {
  BinaryTree bt;
  bt.buildMockTree();
  bt.printLeftView();
  return 0;
}
