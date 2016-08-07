#include <iostream>
using namespace std;

int* mergeSortedArrays(int arr1[], int len1, int arr2[], int len2) {
	int* resultArr;
	resultArr=new int[len1+len2];
	int i=0, j=0;
	for(int k=0;k<len1+len2;k++) {
		if(i==len1) {
			resultArr[k] = arr2[j];
			j+=1;	
                } else if(j==len2) {
			resultArr[k] = arr1[i];
			i+=1;
		} else if(arr1[i]<=arr2[j]) {
			resultArr[k] = arr1[i];
			i+=1;
		} else {
			resultArr[k] = arr2[j];
			j+=1;
		}
	}

	
	return resultArr;
}

void printArray(int *arr, int len) {
	for(int i=0; i<len; i++) {
		cout<<" "<<arr[i];
	}	
}

int main() {
	int arr1[] = {5, 6, 9, 11};
	int arr2[] = {2, 3, 6, 8};
	int *result = mergeSortedArrays(arr1,4,  arr2, 4);
	printArray(result, 8);
	return 0;
}
