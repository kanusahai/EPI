#include<iostream>

using namespace std;

class Shares {

	private:
	float* prices;
	int len;

	float maxProfit(int start) {
		if(prices==NULL || len==0) return 0;
		if(start>=len-1) return 0;
		float minSoFar=prices[start];
		float maxProf=-999999999;

		for(int i=start+1;i<len;i++) {
			if(prices[i]-minSoFar>maxProf) {
				maxProf=prices[i]-minSoFar;
			}
			if(prices[i]<minSoFar) minSoFar=prices[i];
		}
		return maxProf;
	}

	public:
	Shares() { 
		prices=NULL;
		len=0;
	}

	Shares(float* prices, int len) {
		this->prices=prices;
		this->len=len;
	}

	float maxProfit() {
		maxProfit(0);
	}

	float maxProfitTwice() {
		if(prices==NULL || len<=1) return 0;
		float maxProf=-99999999;
		float minSoFar=prices[0];

		for(int i=1;i<len;i++) {
			float profit = prices[i]-minSoFar + maxProfit(i+1);
			if(profit>maxProf) maxProf=profit;

			if(prices[i]<minSoFar) minSoFar=prices[i];
		}

		return maxProf;
	}

	float maxProfitTwiceExtraSpace() {
		if(len<=1 || prices==NULL) return 0;
		float profit[len+1];	
		profit[len]=0;
		profit[len-1]=0;
		float maxSoFar=prices[len-1];
		float maxProf=prices[len-1]-prices[len-2];
		for(int j=len-2;j>=0;j--) {
			if(maxSoFar-prices[j]>maxProf) maxProf = maxSoFar-prices[j];
			profit[j]=maxProf;
			if(prices[j]>maxSoFar) maxSoFar=prices[j];
		}

		maxProf=-99999999;
		float minSoFar=prices[0];

		for(int i=1;i<len;i++) {
			float prof = prices[i]-minSoFar + profit[i+1];
			if(prof>maxProf) maxProf=prof;

			if(prices[i]<minSoFar) minSoFar=prices[i];
		}

		return maxProf;
	
		

	}

};


int main() {
	float arr[6]={1,3,2,4,1,1};
	Shares s(arr, 6);
	cout<<s.maxProfitTwice()<<"\n";
	cout<<s.maxProfitTwiceExtraSpace()<<"\n";
	return 0;
}
