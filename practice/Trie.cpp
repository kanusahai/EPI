#include<iostream>
#include<cstring>
using namespace std;

struct trieNode {
  int isLeaf;
  trieNode* arr[26];
};

class Trie {
  private:
  trieNode* root;

  public:
  Trie() {
    root=NULL;
  } 

  void insert(const char *str) {
    if(root==NULL) {
      root=new trieNode();
      root->isLeaf=0;
      for(int i=0;i<26;i++)
        root->arr[i]=NULL;
    }
    trieNode* curNode=root;
    for(int i=0;i<strlen(str);i++) {
      int val=str[i]-'a';
      if(curNode->arr[val]!=NULL) {
        curNode=curNode->arr[val]; 
      } else {
        curNode->arr[val]=new trieNode();
        curNode=curNode->arr[val];
        for(int i=0;i<26;i++)
          curNode->arr[i]=NULL;
      }
    }
    curNode->isLeaf=1;
  }

  bool find(const char *str) {
    if(root==NULL)
      return false;

    trieNode* curNode=root;
    for(int i=0;i<strlen(str);i++) {
      int val=str[i]-'a';
      if(curNode->arr[val] ==NULL)
        return false;

      curNode=curNode->arr[val];
    }
    if(curNode->isLeaf==1)
      return true;
    else
      return false;
  }
};

int main() {
  char str[]="hello";
  Trie t;
  t.insert(str);
  t.insert("hell");
  t.insert("yo");

  if(t.find("hell"))
    cout<<"Yay!\n";
  else
    cout<<"No!\n";
  return 0;
}
