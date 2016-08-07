#include <iostream>
using namespace std;

void mergeSort(int *arr, int l, int u) {
  if(l>=u)
    return;

  int m=(l+u)/2;

  mergeSort(arr, l, m);
  mergeSort(arr, m+1, u);

  int *extraSpace=new int[u-l+1];
  int p=l;
  int q=((m+1)>u)?u:m+1;
  for(int i=0; i<u-l+1;i++) {
    if(p<m+1 && q<u+1) {
      if(arr[p]<arr[q]) {
        extraSpace[i]=arr[p];
        p+=1;
      } else {
        extraSpace[i]=arr[q];
        q+=1;
      }
    } else if(p>m) {
      extraSpace[i]=arr[q];
      q+=1;
    } else {
      extraSpace[i]=arr[p];
      p+=1; 
    }

  }
  
  for(int i=l;i<=u;i++) {
    arr[i]=extraSpace[i-l];
  }
  delete [] extraSpace;
}

void mergeSort(int *arr, int n) {
 mergeSort(arr, 0, n-1);
}

void print(int* arr, int n) {
  for(int i=0; i<n; i++) {
    cout<<arr[i];
    cout<<"\n";
  }
}
int main() {
  int arr[]={12,3,14,5};
  
  mergeSort(arr, 4);
  print(arr, 4);
  return 0;
}
