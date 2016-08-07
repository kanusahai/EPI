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

  void insert(int num) {
    if(head==NULL) {
      head=new node();
      head->val=num;
      head->next=NULL;
      return;
    }
    node* p=head;
    while(p->next!=NULL) 
      p=p->next;

    p->next=new node();
    p->next->val=num;
    p->next->next=NULL;
  }

  void perfectShuffle() {
    if(head==NULL)
      return;
    node* p=head;
    node* q=head;
    node* temp=head;
    while(q!=NULL && q->next!=NULL) {
      temp=p;
      p=p->next;
      q=q->next->next;
    }
    temp->next=NULL;
    node* head2=p;
    node* head1=head;
    
    while(head1->next!=NULL && head2!=NULL) {
      temp=head1->next;
      head1->next=head2;
      head2=head2->next;
      head1->next->next=temp;
      head1=temp;
      
    }

    if(head2!=NULL && head1!=head2)
      head1->next=head2;  
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
  LL ll;
  ll.insert(1);
  ll.insert(2);
  ll.insert(3);
  ll.insert(4);
  ll.insert(5);

  ll.perfectShuffle();

  ll.print();
  return 0;
}
