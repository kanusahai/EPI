#include<iostream>
#include<map>
using namespace std;


struct node {
  int value;
  node* next;
};

node* head;
map<int,int> hashMap;
void removeDup() {
  if(head==NULL)
    return;
  node* p=head;
  node* q=p->next;
  hashMap[p->value]=1;
  while(q!=NULL) {
    if(hashMap[q->value]==1) {
      p->next=q->next;
      node* temp=q;
      q=q->next;
      delete(temp);      
    } else {
      hashMap[q->value]=1;
      q=q->next;
      p=p->next;
    }
  }
}

void removeDupWithNoExtraSpace() {
  if(head==NULL)
    return;

  node* current=head;
  node* p;
  node* q;
  while(current->next!=NULL) {
    p=current;
    q=current->next;

    while(q!=NULL) {
      if(q->value==current->value) {
        p->next=q->next;
        node* temp=q;
        q=p->next;
        delete(temp);
      } else {
        p=p->next;
        q=q->next;
      }
    }
    current=current->next;

  }  
}



void printLL() {
  if(head==NULL)
    return;

  node* p=head;
  while(p!=NULL) {
    cout<<p->value<<" ";
    p=p->next;
  }
}

void addToLL(int val) {
  if(head==NULL) {
    head=new node();
    head->value=val;
    head->next=NULL;
  } else {
    node* p=head;
    while(p->next!=NULL) 
      p=p->next;
    p->next=new node();
    p->next->next=NULL;
    p->next->value=val;
  }
}
int main() {
  addToLL(4);
  addToLL(5);
  addToLL(4);
  addToLL(7);
  removeDupWithNoExtraSpace();
  //removeDup();
  printLL();
}
