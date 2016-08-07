#include<iostream>
#include<vector>
using namespace std;

struct node {
  int value;
  node* nodePtr;
};
class SetOfStacks {
  private:  
  int threshold;
  vector<node> stacks; //Node contains size of stack and pointer to Top of stack

  public:
  
  SetOfStacks(int thresh) {
    this->threshold=thresh;
  }

  void push(int num) {
    if(stacks.size()==0 || stacks.back().value==threshold) {
      node n;
      n.value=1;
      n.nodePtr=new node();
      n.nodePtr->value=num;
      n.nodePtr->nodePtr=NULL;
      stacks.push_back(n);
    } else {
      stacks.back().value+=1;
      node *newTop=new node();
      newTop->value=num;
      newTop->nodePtr=stacks.back().nodePtr;
      stacks.back().nodePtr=newTop;
    }
  }
  
  int pop() {
   int result=-99999; 
   if(stacks.size()>0) {
      result=stacks.back().nodePtr->value;
      node *newTop=stacks.back().nodePtr->nodePtr;
      if(newTop!=NULL) {
        delete(stacks.back().nodePtr);
        stacks.back().nodePtr=newTop;
        stacks.back().value-=1;
      } else {
        stacks.pop_back();
      }
    }
    return result;
  }
};


int main() {
  SetOfStacks sos(2);
  sos.push(3);
  sos.push(5); 
  sos.push(7);
  cout<<sos.pop()<<"\n";
  cout<<sos.pop()<<"\n"; 
  cout<<sos.pop()<<"\n";
  return 0;
} 
