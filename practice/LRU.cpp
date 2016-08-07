#include<iostream>

using namespace std;

struct node {
  int value;
  node *next;
};
class LRU {

  private:
  node** arr;
  int size;
  int assoc;
  int *sizeArr;
  public:
  LRU(int size, int assoc) {
    this->size=size;
    this->assoc=assoc;
    arr=new node*[size];
    for(int i=0;i<size;i++)
      arr[i]=NULL;

    sizeArr=new int[size];
    for(int i=0;i<size;i++)
      sizeArr[i]=0;

  } 

  bool get(int val) {
    int index=val%size;
    if(arr[index]==NULL) {
      arr[index]=new node();
      arr[index]->next=NULL;
      arr[index]->value=val;
      sizeArr[index]+=1;
      return false;
    }
    node *p =arr[index];
    if(sizeArr[index]==1 && p->value==val)
      return true; 
    else if(p->value==val) {
      arr[index]=p->next;
      node *q=arr[index];
      while(q->next!=NULL)
        q=q->next;
      q->next=p;
      p->next=NULL;
      return true;
    }
    node *q=p->next;
    while(q!=NULL) {
      if(q->value==val) {
          p->next=q->next;
          while(p->next!=NULL) 
            p=p->next;
          p->next=q;
          q->next=NULL;
          return true;
      }
      q=q->next;
      p=p->next;
    }
    
    p->next=new node();
    p->next->value=val;
    p->next->next=NULL;
    
    if(sizeArr[index]==assoc) {      
      node *startNode=arr[index];
      arr[index]=startNode->next;
      delete(startNode);
    } else {
      sizeArr[index]+=1;
    }
    return false;
  }

};

int main() {
  LRU cache(4,2);
  if(!cache.get(1)) cout<<"Inserted 1\n"; else cout<<"Got 1\n";
  if(!cache.get(5)) cout<<"Inserted 5\n"; else cout<<"Got 5\n";
  if(!cache.get(9)) cout<<"Inserted 9\n"; else cout<<"Got 9\n";
  if(!cache.get(5)) cout<<"Inserted 5\n"; else cout<<"Got 5\n";
  if(!cache.get(1)) cout<<"Inserted 1\n"; else cout<<"Got 1\n";
  if(!cache.get(9)) cout<<"Inserted 9\n"; else cout<<"Got 9\n";
  if(!cache.get(5)) cout<<"Inserted 5\n"; else cout<<"Got 5\n";
  return 0;
}
