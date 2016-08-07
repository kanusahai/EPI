#include<iostream>


using namespace std;

struct node {
  int val;
  node* right;
  node* left;
};

class BinaryTreeOfMinHeight {
  private:
  node* root;

  node* createFromSortedArr(int* arr, int n, int l, int u) {
    if(l>u)
      return NULL;

    int m=(l+u)/2;
    node* newNode=new node();
    newNode->val=arr[m];
    newNode->left=createFromSortedArr(arr, n, l, m-1);
    newNode->right=createFromSortedArr(arr, n, m+1, u);

    return newNode;
  }

  void printInorder(node* p) {
    if(p==NULL)
      return;
    printInorder(p->left);
    cout<<p->val<<" ";
    printInorder(p->right);
  }
  public:
  BinaryTreeOfMinHeight() {
    root=NULL;
  }

  BinaryTreeOfMinHeight(int* arr, int n) {
    root=createFromSortedArr(arr, n, 0, n-1);
  } 

  void printInorder() {
    printInorder(root);
    cout<<"\n";
  }
};

int main() {

  int arr[5]={1,2,3,4,5};
  BinaryTreeOfMinHeight bt(arr, 5);
  bt.printInorder();
  return 0;
}
