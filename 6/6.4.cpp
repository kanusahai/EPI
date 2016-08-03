#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

class OfflineData {
	private:
	int* arr;
	int len;

	public:
	OfflineData(int* arr, int len) {
		this->arr=arr;
		this->len=len;
	}

	/*~OfflineData() {
		delete arr;
		len=0;
	}*/

	void printKSample(int k) {
		if(len<k) return;
		for(int i=0;i<k;i++) {
			cout<<arr[i]<<" ";
		}
		cout<<"\n";
	}

	void generateKSample(int k) {
		if(k>=len) return;
		srand (time(NULL));	
		for(int i=k;i<len;i++) {
			int random = rand()%(i+1);
			cout<<"Random number: "<<random<<"\n";
			int temp = arr[random];
			arr[random]=arr[i];
			arr[i]=temp;
		} 
	}

};

int main() {
	int arr[6]={1,2,3,4,5,6};
	OfflineData od(arr, 6);
	od.generateKSample(3);
	od.printKSample(3);
	return 0;
}
