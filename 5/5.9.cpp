#include<iostream>
#include<cmath>

using namespace std;

class PalindromicInt {
	private:
	int length(int num) {
		if(num==0) return 1;
		if(num<0) return -1;
		int len=0;
		while(num) {
			num/=10;
			len++;
		}
		return len;
	}
	public:
	bool isPalindrome(int num) {
		int len=length(num);
		if(len<=0) return false;

		while(len>=2) {
			int lsb=num%10;
			int msb=num/pow(10,len-1);
			if(lsb!=msb) return false;	
			num-=msb*pow(10,len-1);
			num/=10;
			len-=2;
		}
		return true; 
	}
};

int main() {
	PalindromicInt pi;
	cout<<pi.isPalindrome(468)<<"\n";
	cout<<pi.isPalindrome(-121)<<"\n";
	cout<<pi.isPalindrome(0)<<"\n";
	cout<<pi.isPalindrome(321121123)<<"\n";
	return 0;
}
