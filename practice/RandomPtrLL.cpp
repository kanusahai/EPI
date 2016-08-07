#include<iostream>
#include<map>
using namespace std;

struct node {
  int val;  
  node* next;
  node* random;
};

class LL {
  private:
  node* head; 
  
  public:
  LL() {
    head=NULL;
  }

  void setHead(node* h) {
    this->head=h;
  }

  void insert(int num) {
    node* newNode=new node();
    newNode->val=num;
    newNode->next=NULL;
    newNode->random=NULL;
    
    if(head==NULL) {
      head=newNode;
      return;
    }
    node* p=head;
    while(p->next!=NULL)
      p=p->next;

    p->next=newNode; 
  }

  void setRandomPtr(int point, int randomPoint) {
    node* q=head;
    node* pt=NULL;
    node* rPt=NULL;

    while(q!=NULL) {
      if(q->val==randomPoint) {
        rPt=q;
      }
      if(q->val==point) {
        pt=q;
      }
      q=q->next;
    }

    pt->random=rPt;
  }
 
  LL clone() {
    map<node*, node*> hash;
    map<node*, node*> cloneHash;
    node* p=head;
    
    while(p!=NULL) {
      hash[p]=p->random;
      node* newNode=new node();
      newNode->val=p->val;
      newNode->next=NULL;
      newNode->random=NULL;
      cloneHash[p]=newNode;
      p=p->next;
    }
     
    p=head;
    while(p!=NULL) {
      cloneHash[p]->next=cloneHash[p->next];
      cloneHash[p]->random=cloneHash[hash[p]];
      p=p->next;
    }    
    
    LL ll;
    ll.setHead(cloneHash[head]);
    return ll;
  }

  void print() {
    node* p=head;

    while(p!=NULL) {
      cout<<"Value: "<<p->val<<" Random_Value: "<<p->random->val<<"\n";
      p=p->next;
    }
  }
};

int main() {
  LL ll1;
  ll1.insert(2);
  ll1.insert(3);
  ll1.insert(4);
  ll1.insert(5);

  ll1.setRandomPtr(2,4);
  ll1.setRandomPtr(3,2);
  ll1.setRandomPtr(4,2);
  ll1.setRandomPtr(5,3);

  LL ll2=ll1.clone();

  ll2.print();
  return 0;
}
