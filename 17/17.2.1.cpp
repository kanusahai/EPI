#include<iostream>

using namespace std;

int numOfMonotones( int k) {
	if(k<=0) return 0;
	int arr[10];
	for(int j=9;j>=1;j--) arr[j]=10-j;

	for(int i=2;i<=k;i++) {
		for(int j=9;j>=1;j--) {
			if(j+1<10) arr[j]+=arr[j+1];		
		}
	}

	return arr[1];
}

int main() {
	cout<<numOfMonotones(3)<<"\n";
	return 0;
}
