#include<iostream>
#include<stack>

using namespace std;

//Assumption: Stack contains positive integers
//Approach2 : Using addition

class MaxStackOptimized {
	private:
	stack<int> originalStack;
	int curMaxVal;

	public:
	MaxStackOptimized() {
		curMaxVal=0;
	}

	void push(int val) {
		int valToPush;
		if(val>curMaxVal) {	
			valToPush=curMaxVal+val;
			curMaxVal=val;
		} else {
			valToPush=val;
		}		
		originalStack.push(valToPush);
	}

	int pop() {
		if(originalStack.empty()) return -1; //Error code
		int stackTop = originalStack.top();
		int retVal = stackTop;
				
		if(stackTop>curMaxVal) {	
			retVal=curMaxVal;
			curMaxVal= stackTop-curMaxVal;	
		}
		originalStack.pop();	
		return retVal;
	}

	int getMax() {
		return curMaxVal;
	}

	int size() {
		return originalStack.size();
	}

};

int main() {
	MaxStackOptimized mso;
	mso.push(5);
	mso.push(4);
	mso.push(5);
	mso.push(7);
	mso.push(6);
	
	for(int i=0;i<5;i++) {
		cout<<mso.getMax()<<"\n";
		mso.pop();
	}
	return 0;
}	
