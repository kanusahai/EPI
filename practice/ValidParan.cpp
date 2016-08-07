#include<iostream>

using namespace std;

void print(int numOp, int numCl, int pos, char *arr, int n) {
  if(pos==n) {
    cout<<arr<<"\n";
    return;
  }

  if(numOp>numCl) {
    arr[pos]=')';
    print(numOp, numCl+1, pos+1, arr,n);
  }

  if(numOp<n/2) {
    arr[pos]='(';
    print(numOp+1, numCl, pos+1, arr,n);
  }

}

void printValidParanPair(int numOfPair) {
  char arr[2*numOfPair];
  print(0,0,0,arr,2*numOfPair);
}

int main() {
  printValidParanPair(3);
  return 0;
}
