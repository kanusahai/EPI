#include<iostream>
#include<string>

using namespace std;

struct node {
  char val;
  node* left;
  node* right;
};

class BT {
  private:
  node* root;

  void inorder(node* p) {
    if(p==NULL)
      return;

    inorder(p->left);
    cout<<p->val<<" ";
    inorder(p->right);
  }

  public:
  BT() {
    root=NULL;
  }

  void generate(string pre, string in) {
    if(pre.length()!=in.length() || pre.empty()) 
      return;
    root=new node();
    root->val=pre[0];

    int i;
    for(i=0;i<in.length();i++)
      if(in[i]==pre[0])
        break;
    BT leftBT;
    string leftIn=in.substr(0,i);
    string leftPre=pre.substr(1,i);
    leftBT.generate(leftPre, leftIn);
    root->left=leftBT.getRoot();

    BT rightBT;
    string rightIn=in.substr(i+1,in.length()-i-1);
    string rightPre=pre.substr(i+1,pre.length()-i-1);
    rightBT.generate(rightPre, rightIn);
    root->right=rightBT.getRoot();
    
  }

  node* getRoot() {
    return root;
  }

  void printInorder() {
    inorder(root);
    cout<<"\n";
  }
};

int main() {
  BT bt;
  bt.generate("abc", "bac");
  bt.printInorder();  
  return 0;
}

