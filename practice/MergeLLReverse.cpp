#include<iostream>

using namespace std;

struct node {
  int val;
  node* next;
};

class LL {
  private:
  node* head;
  
  public:
  LL() {
    head=NULL;
  }

  ~LL() {
    node* temp=NULL;
    while(head!=NULL) {
     temp=head;
     head=head->next;
     //delete(temp);
    }
  }

  void setHead(node* p) {
    head=p;
  }

  node* getHead() {
    return this->head;
  }

  void insert(int num) {
    node* newNode=new node();
    newNode->val=num;
    newNode->next=NULL;
    if(head==NULL) {
      head=newNode;
      return;
    }
    node* p=head;
    while(p->next!=NULL)
      p=p->next;
    p->next=newNode;
  }

  LL mergeReverse(LL& ll) {   
    LL testLL;
    node* p=head;
    node* q=ll.getHead();
    
    node* tail=NULL;
    while(p!=NULL && q!=NULL) {
      if(p->val<=q->val) {
       node* temp=p->next;
       p->next=tail;
       tail=p;
       p=temp; 
      } else {
       node* temp=q->next;
       q->next=tail;
       tail=q;
       q=temp;
      }
    }

    while(p!=NULL) {
      node* temp=p->next;
      p->next=tail;
      tail=p;
      p=temp;
    }
    while(q!=NULL) {
      node* temp=q->next;
      q->next=tail;
      tail=q;
      q=temp;
    }

    testLL.setHead(tail);
    return testLL;
  }

  void print() {
    node* p=head;
    while(p!=NULL) {
      cout<<p->val<<" ";
      p=p->next;
    }
    cout<<"\n";
  }
};

int main() {
  LL ll1;
  ll1.insert(2);
  ll1.insert(6);
  ll1.insert(9);

  LL ll2;
  ll2.insert(3);
  ll2.insert(7);

  LL ll3=ll1.mergeReverse(ll2);
  ll3.print();
  return 0;
}
