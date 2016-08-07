#include<iostream>

using namespace std;

void print(int *bitArr, int *arr, int pos, int n) {
  if(pos==n) {
    for(int i=0;i<n;i++) {
      if(bitArr[i]==1)
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    return;
  }

  bitArr[pos]=0;
  print(bitArr, arr, pos+1,n);
  bitArr[pos]=1;
  print(bitArr, arr, pos+1,n); 
}

void printAllSubset(int *arr, int n) {
 int bitArr[n];
 print(bitArr,arr,0,n);
}

int main() {
  int arr[3]={1,2,3};
  printAllSubset(arr,3);
  return 0;
}
