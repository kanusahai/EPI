#include<iostream>

using namespace std;


int numOfWays(int *arr, int n, int sum) {
  int L[sum+1][n];

  for(int j=0;j<n;j++)
    L[0][j]=1;

  for(int i=1;i<sum+1;i++) {
    if(i%arr[0]==0) {
      L[i][0]=1;
    } else {
      L[i][0]=0;
    }
  }

  for(int j=1;j<n;j++) 
  for(int i=1;i<sum+1;i++) {
    int k=arr[j];
    L[i][j]=0;
    L[i][j]+=L[i][j-1];
    while(k<=i) {
      L[i][j]+=L[i-k][j-1];
      k+=arr[j];
    }
  }
   
  return L[sum][n-1];

}

int main() {
  int arr[4]={2,5,3,6};
  cout<<numOfWays(arr, 4, 10)<<"\n";
  return 0;
}
