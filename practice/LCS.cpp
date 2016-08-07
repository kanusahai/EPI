#include<iostream>

using namespace std;

struct HtWt {
  int ht;
  int wt;
};

void sort(HtWt* arr, int n, int value) {
  if(value==1) {
    for(int i=0;i<n-1;i++) 
    for(int j=i+1;j<n;j++) {
      if(arr[j].ht<arr[i].ht) {
        HtWt temp=arr[j];
        arr[j]=arr[i];
        arr[i]=temp;
      }
    }

  } else if(value==2) {
    for(int i=0;i<n-1;i++) 
    for(int j=i+1;j<n;j++) {
      if(arr[j].wt<arr[i].wt) {
        HtWt temp=arr[j];
        arr[j]=arr[i];
        arr[i]=temp;
      }
    }

  }
}

int maxTowerLength(HtWt* arr, int n) {

  HtWt sortedByHt[n];
  HtWt sortedByWt[n];

  for(int i=0;i<n;i++) {
    sortedByHt[i]=arr[i];
    sortedByWt[i]=arr[i];
  }

  sort(sortedByHt, n, 1);
  sort(sortedByWt, n, 2);
   
  int L[n+1][n+1];
  for(int i=0;i<n+1;i++)
    L[i][0]=0;

  for(int j=0;j<n+1;j++) 
    L[0][j]=0;

  for(int i=1;i<n+1;i++)
  for(int j=1;j<n+1;j++) {
    int temp=L[i-1][j-1];
    if(sortedByHt[i-1].ht==sortedByWt[j-1].ht && sortedByHt[i-1].wt==sortedByWt[j-1].wt)
      temp+=1;
    if(temp<L[i-1][j])
      temp=L[i-1][j];
    if(temp<L[i][j-1])
      temp=L[i][j-1];

    L[i][j]=temp;
  }

  return L[n][n];
}

int main() {
  HtWt arr[]={65,100,70,150,56,90,75,190,60,95,68,110};
  cout<<maxTowerLength(arr, sizeof(arr)/sizeof(HtWt))<<"\n";
}
