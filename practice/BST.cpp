#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct node {
  int value;
  node* right;
  node* left;
};

class BST {
  private:
  node* root;
  int size;
  void put(node* p, int val) {
    if(p==NULL) 
      return;

    if(p->value>=val) {
      if(p->left==NULL) {
        p->left=new node();
        p->left->value=val;
        p->left->left=NULL;
        p->left->right=NULL;
        return;
      } else {
        put(p->left, val);
        return;
      }

    } else {
      if(p->right==NULL) {
        p->right=new node();
        p->right->right=NULL;
        p->right->left=NULL;
        p->right->value=val;
        return;
      } else {
        put(p->right, val);
        return;
      }
    }
  }

  bool get(node* p, int val) {
    if(p==NULL)
      return false;

    if(p->value==val)
      return true;

    if(p->value>val)
      return get(p->left, val);

    return get(p->right, val);
  }

  void inOrder(int* arr, node* p, int *pos) {
    if(p==NULL)
      return;

    inOrder(arr, p->left, pos);
    arr[*pos]=p->value;
    *pos+=1;
    inOrder(arr, p->right, pos);

    return;
  }

  public: 

  BST() {
    root=NULL;
    size=0;
  }

  ~BST() {
    if(root!=NULL)
      delete root;
  }

  void put(int val) {
    if(root==NULL) {
      root=new node();
      root->value=val;
      root->left=NULL;
      root->right=NULL;
    } else {
      put(this->root, val);
    }
    size+=1;
  }

  bool get(int val) {
    return get(this->root, val);
  }

  int getClosest(int val) {
    node* p=root;
    int closestSoFar=0;
    while(p!=NULL) {
      if(p->value==val)
        return val;

      if(p->value<val) {
        if(val-p->value<val-closestSoFar)
          closestSoFar=p->value;
        p=p->right;
      } else {
        p=p->left;
      }
    }
    return closestSoFar;
  }

  int* inOrder () {
    int* result=new int[size];
    int *pos=new int(0);
    inOrder(result, root, pos);
    return result;
  }
  vector<int> getCommon(BST& bst) {
    vector<int> vec;
    int* arrA=this->inOrder();
    int* arrB=bst.inOrder();
    int sizeB=bst.getSize();
    int i=0;
    int j=0;

    while(i<size && j<sizeB) {
      if(arrA[i]==arrB[j]) {
        vec.push_back(arrA[i]);
        i+=1;
        j+=1;
      } else if(arrA[i]<arrB[j]) {
        i+=1;
      } else {
        j+=1;
      }
    }  
    return vec;
  }

  int getSize() {
    return size;
  }
};



int main() {

  BST bst;

  bst.put(5);
  bst.put(7);
  bst.put(99);
  bst.put(1);

  //if(bst.get(99)) 
    //cout<<"Yay!\n";

  //if(!bst.get(97))
    //cout<<bst.getClosest(97)<<"\n";
  //int* inOrderArr=bst.inOrder();
  //for(int i=0;i<bst.getSize();i++) {
    //cout<<inOrderArr[i]<<" "; 
  //}
  //cout<<"\n";
 
  BST bst2;

  bst2.put(7);
  bst2.put(5);
  bst2.put(67);
  bst2.put(101);
  
  vector<int> vec=bst.getCommon(bst2);

  for(int i=0;i<vec.size();i++)
    cout<<vec[i]<<" ";
  cout<<"\n";
  return 0;
}
