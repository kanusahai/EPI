#include<iostream>
#include<vector>

using namespace std;

struct node {
  int val;
  node* right;
  node* left;
};

class BT {
  private:
  node* root;

  bool getPath(vector<int> &vec, node* p, int num) {
    if(p==NULL)
      return false;
    
    vec.push_back(p->val);
    if(p->val==num) 
      return true;
    
    if(getPath(vec, p->left, num))
      return true;
    if(getPath(vec, p->right, num))
      return true;

    vec.pop_back();
    return false;
  } 
  public: 
  BT() {
    root=NULL;
  }

  void insert(int num) {

  }

  vector<int> getPath(int num) {
    vector<int> vec;
    getPath(vec, root, num);
    return vec;
  }

  int lca(int num1, int num2) {
     vector<int> path1=getPath(num1);
     vector<int> path2=getPath(num2);

     int len=(path1.size()>path2.size())?path2.size():path1.size();
     for(int i=0;i<len;i++) {
       if(path1[i]==path2[i])
         continue;
       else
         return path1[i-1];
     }
     
     if(path1.size()<=path2.size())
       return num1;
     else
       return num2;
  }
};


int main() {

  return 0;
}
