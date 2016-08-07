#include<iostream>
using namespace std;

struct node {
  int value;
  node* next;
};

class Stack {
  private:
  node* top;

  public:
  Stack() {
    top=NULL;
  }

  void push(int num) {
    if(top==NULL) {
      top=new node();
      top->value=num;
      top->next=NULL;
    } else {
      node* newTop=new node();
      newTop->value=num;
      newTop->next=top;
      top=newTop;
    }
  }

  int pop() {
    int result=-999999;
    if(top!=NULL) {
      result=top->value;
      node* temp=top;
      top=top->next;
      delete(temp);
    }
    return result;
  }

  void print() {
    if(top==NULL) 
      cout<<"empty\n";
    else {
      node* p=top;
      while(p!=NULL) {
        cout<<p->value<<" ";
        p=p->next;
      }
      cout<<"\n";
    }
  }

};

class TowerOfHanoi {
  private:
  Stack tower[3];
  int size;

  void initialize() {
    for(int i=size;i>0;i--)
      tower[0].push(i);
  }

  void solve(int source, int destination, int size) {
    if(size==1) {
      int num=tower[source].pop();
      tower[destination].push(num);
      return;
    }

    solve(source, 3-(source+destination),size-1);
    solve(source, destination, 1);
    solve(3-(source+destination), destination, size-1);
  }

  public:
  
  TowerOfHanoi(int size) {
    this->size=size;
    initialize();
  }

  bool solve() {
    if(this->size<=0)
      return false;
    solve(0,2,this->size);
    return true;
  }

  void printTowers() {
    cout<<"Tower 1:\n";
    tower[0].print();
    cout<<"Tower 2:\n";
    tower[1].print();
    cout<<"Tower 3:\n";
    tower[2].print();
  }
};


int main() {
  TowerOfHanoi toh(5);
  toh.printTowers();
  cout<<"\n";
  if(toh.solve()) {
    toh.printTowers();
  } 
  return 0;
}
