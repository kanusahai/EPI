#include <iostream>
using namespace std;

void printMatrixWithInwardSpiral(int **matrix, int m, int n) {
	int startRow=0;
	int startCol=0;
	while(m>=0 && n>=0) {	
		for(int j=startCol;j<startCol+n;j++)
			cout<<matrix[startRow][j];
		
		for(int i=startRow+1;i<startRow+m;i++)
			cout<<matrix[i][startCol+n-1];
		if(m>1) {
			for(int j=startCol+n-2;j>=startCol;j--)
				cout<<matrix[startRow+m-1][j];
		}
		if(n>1) {
			for(int i=startRow+m-2;i>=startRow+1;i--)
				cout<<matrix[i][startCol];
		}
		m-=2;
		n-=2;
		startRow+=1;
		startCol+=1;
	}
	
}

int main() {
	int* matrix[3];
	for(int i=0;i<3;i++)
		matrix[i]=new int[4];
		
	int count=1;
	for(int i=0;i<3;i++)
	for(int j=0;j<4;j++) {
		matrix[i][j]=count;
		count+=1;
	}
	
	printMatrixWithInwardSpiral(matrix, 3,4);
	return 0;
}
