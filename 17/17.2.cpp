#include<iostream>

using namespace std;

int numOfWays(int n, int m) {
	int arr[n][m];
	for(int i=0;i<n;i++)
		arr[i][m-1]=1;
	for(int j=0;j<m;j++)
		arr[n-1][j]=1;

	for(int j=m-2;j>=0;j--)
	for(int i=n-2;i>=0;i--) {
		arr[i][j]=arr[i+1][j] + arr[i][j+1];
	}
	return arr[0][0];
}

int main() {
	cout<<numOfWays(5,5)<<"\n";
	return 0;
}
