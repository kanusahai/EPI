#include<iostream>

using namespace std;

class BST {
  private:

  class Node {
    private:
    int val;
    Node* left;
    Node* right;

    public:
    Node() {
      left=NULL;
      right=NULL;
      val=0;
    }

    Node(int val, Node* left, Node* right) {
      this->val=val;
      this->left=left;
      this->right=right;
    }

    int getVal() {
      return val;
    }

    Node* getLeft() {
      return left;
    }

    Node* getRight() {
      return right;
    }

    void setVal(int val) {
      this->val=val;
    }

    void setLeft(Node* left) {
      this->left=left;
    }

    void setRight(Node* right) {
      this->right=right;
    }
  };

  Node* root;

  public:
  BST() {
    root=NULL;
  }

  void insert(int num) {
    Node* newNode=new Node(num, NULL, NULL);
    if(root==NULL) {
      root=newNode;
      return;
    }

    Node* curNode=root;
    bool notPlaced=true;
    while(notPlaced) {
      if(num<=curNode->getVal()) {
        if(curNode->getLeft()==NULL) {
          curNode->setLeft(newNode);
          notPlaced=false;
        } else {
          curNode=curNode->getLeft();
        }
      } else {
        if(curNode->getRight()==NULL) {
          curNode->setRight(newNode);
          notPlaced=false;
        } else {
          curNode=curNode->getRight();
        }
      }
    }
    return;
  }

  int secondLargest() {
    if(root==NULL)
      return -99999;

    Node* curNode=root;

    while(curNode!=NULL) {
      if(curNode
    }
  }
};

int main() {
  BST bst;
  bst.insert(2);
  bst.insert(1);
  bst.insert(3);
  return 0;
}
