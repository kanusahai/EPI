#include <iostream>
#include<vector>
#include<queue>

using namespace std;

struct node {
  int val;
  node* right;
  node* left;
};
class BST {
  private:
  node* root;
  public:
  BST() {
    root=NULL;
  }
  
  void insert(int num) {
    if(root==NULL) {
      root=new node();
      root->val=num;
      root->right=NULL;
      root->left=NULL;
      return;
    }    
    node* p=root;
    while(p!=NULL) {
      if(p->val>=num) {
        if(p->left==NULL) {
          node* newNode=new node();
          newNode->right=NULL;
          newNode->left=NULL;
          p->left=newNode;
          return;
        } else {
          p=p->left;
        }
      } else {
        if(p->right==NULL) {
          node* newNode=new node();
          newNode->right=NULL;
          newNode->left=NULL;
          p->right=newNode;
          return;
        } else {
          p=p->right;
        }
      }
    }
    return;
  }
  
  bool find(int num) {
    return true;    
  }
  
  vector<node*> convertIntoLL() {
    vector<node*> vec;
    if(root==NULL) {
      return vec;
    }
    
    queue<node*> q;
    q.push(root);
    
    int numOfNodesAtCur=1;
    int numOfNodesAtNext=0;
    bool isHead=true;
    node* tailCurLevel=NULL;
    while(!q.empty()) {
      node* temp=q.front();
      q.pop();
      
      if(temp->left!=NULL) {
        q.push(temp->left);
        numOfNodesAtNext+=1;
      }
      
      if(temp->right!=NULL) {
        q.push(temp->right);
        numOfNodesAtNext+=1;
      }
      
      if(isHead) {
        vec.push_back(temp);
        isHead=false;
      }
      if(tailCurLevel!=NULL)
        tailCurLevel->right=temp;
      temp->left=tailCurLevel;
      tailCurLevel=temp;
      
      numOfNodesAtCur-=1;
      
      if(numOfNodesAtCur==0) {
        numOfNodesAtCur=numOfNodesAtNext;
        numOfNodesAtNext=0;
        isHead=true;
        temp->right=NULL;
        tailCurLevel=NULL;
      }
    }
    return vec;
  }
};

void print(vector<node*> vec) {
  for(int i=0;i<vec.size();i++) {
    node* temp=vec[i];
    while(temp!=NULL) {
      cout<<temp->val<<" ";
      temp=temp->right;
    }
    cout<<"\n";
  }
}
int main() {
  BST bst;
  bst.insert(2);
  bst.insert(3);
  bst.insert(5);

  vector<node*> vec=bst.convertIntoLL();    
  print(vec);
  return 0;
}
