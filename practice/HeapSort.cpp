#include<iostream>
#include<vector>
using namespace std;

class MaxHeap {

  private:
  vector<int> elem;

  public:
  MaxHeap(vector<int> &vec) {
    for(int i=0;i<vec.size();i++) {
      elem.push_back(vec[i]);
    }
    buildHeap();
  }

  int parentOf(int pos) {
    if(pos%2==0)
      return pos/2-1;

    return pos/2;
  }

  void heapify(int pos) {
    if(elem.empty() || pos>elem.size()-1)
      return;

    int maxVal=elem[pos];
    int rightPos=2*pos+2;
    int leftPos=2*pos+1;

    int switchPos=pos;
    if(leftPos<elem.size() && elem[leftPos]>maxVal) {
      maxVal=elem[leftPos];
      switchPos=leftPos;
    } 
    if(rightPos<elem.size() && elem[rightPos]>maxVal) {
      maxVal=elem[rightPos];
      switchPos=rightPos;
    }  

    elem[switchPos]=elem[pos];
    elem[pos]=maxVal;

    if(switchPos!=pos)
      heapify(switchPos);
  }

  void buildHeap() {
    for(int i=elem.size()/2;i>=0;i--) {
      heapify(i);
    }
  }

  int pop() {
    if(elem.empty())
      return -9999;

    int ret=elem[0];
    elem[0]=elem[elem.size()-1];    
    elem.pop_back();
    heapify(0);
    return ret;
  }

  void insert(int num) {
    elem.push_back(num);
    int pos=elem.size()-1;

    while(pos>0 && elem[pos]>elem[parentOf(pos)]) {
      int temp=elem[pos];
      elem[pos]=elem[parentOf(pos)];
      elem[parentOf(pos)]=temp;
      pos=parentOf(pos);
    }
  }

  void print() {
    for(int i=0;i<elem.size();i++) {
      cout<<elem[i]<<" ";
    }
    cout<<"\n";
  }
};

void heapSort(vector<int> &vec) {
  MaxHeap mh(vec);
  for(int i=vec.size()-1;i>=0;i--)
    vec[i]=mh.pop();  
}

int main() {
  vector<int> vec;
  vec.push_back(4);
  vec.push_back(7);
  vec.push_back(99);
  vec.push_back(9);
  heapSort(vec);

  for(int i=0;i<vec.size();i++)
    cout<<vec[i]<<" ";

  cout<<"\n";
  return 0;
}
