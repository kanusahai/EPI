#include<iostream>

using namespace std;

struct node {
  int value;
  node* next;
};

class LL {
 
  public:
  node* head;
 
  LL() {
    head=NULL;
  } 
  void addToLL(int num) {
    if(head==NULL) {
      head=new node();
      head->value=num;     
      head->next=NULL; 
    } else {
      node* p=head;
      while(p->next!=NULL)
        p=p->next;
      p->next=new node();
      p->next->value=num;
      p->next->next=NULL;
    }
  }

  node* addAnotherLL(const node* h2) {
    int carry=0;
    int sum;
    const node* p=head;
    const node* q=h2;

    node* result=NULL;
    node* tailOfResult=NULL;
    while(p!=NULL && q!=NULL) {
      sum=p->value+q->value+carry;
      carry=sum/10;
      if(result==NULL) {
        result=new node();
        result->value=sum%10;
        result->next=NULL;
        tailOfResult=result;
      } else {
        tailOfResult->next=new node();
        tailOfResult->next->value=sum%10;
        tailOfResult=tailOfResult->next;
        tailOfResult->next=NULL; 
      }
      p=p->next;
      q=q->next;
    }

    while(p!=NULL) {
      tailOfResult->next=new node();
      tailOfResult->next->value=(p->value+carry)%10;
      tailOfResult=tailOfResult->next;
      tailOfResult->next=NULL;
      carry=(p->value+carry)/10;
      p=p->next;
    }
    while(q!=NULL) {
      tailOfResult->next=new node();
      tailOfResult->next->value=(q->value+carry)%10;
      carry=(q->value+carry)/10;
      q=q->next;
      tailOfResult=tailOfResult->next;
      tailOfResult->next=NULL;
    }
    if(carry!=0) {
      tailOfResult->next=new node();
      tailOfResult->next->value=carry;
      tailOfResult=tailOfResult->next;
      tailOfResult->next=NULL;
    }
    
    return result;   
  }
  
  void print(node *p) {
    
    while(p!=NULL) {
      cout<<p->value<<" ";
      p=p->next;
    }
  }

};

int main() {
  
  LL ll1;
  ll1.addToLL(3);
  ll1.addToLL(1);
  ll1.addToLL(5);

  LL ll2;
  ll2.addToLL(5);
  ll2.addToLL(9);
  ll2.addToLL(2);

  node* resultLL=ll1.addAnotherLL(ll2.head);
  ll1.print(resultLL);
  return 0;
}
