#include<iostream>
#include<stack>

using namespace std;

//Assumption: Stack contains positive integers
//Approach1 : Using bit manipulation

class MaxStackOptimized {
	private:
	stack<int> originalStack;
	int curMaxVal;

	public:
	MaxStackOptimized() {
		curMaxVal=0;
	}

	void push(int val) {
		originalStack.push(val^curMaxVal);
		if(val>curMaxVal) {
			curMaxVal=val;
		}		
	}

	int pop() {
		if(originalStack.empty()) return -1; //Error code

		int xorResult = originalStack.top()^curMaxVal;
		originalStack.pop();
		//We can either be popping out the element which equals curMaxVal or some element other than curMaxVal
		//Scenario 1: Popping out curMaxVal element
		//            - Set curMaxVal = Second element obtained after XOR operation of stack's top with curMaxVal
		//	      - The result of pop() operation will be curMaxVal

		//Scenario 2: Not popping out curMaxVal element
		//	      - The result of pop() opeartion = Second element obtained after XOR operation of stack's top with curMaxVal
		//	      - curMaxVal remains

		//Need to make a decision on which scenario it is
		  
		
	}

	int getMax() {
		return curMaxVal;
	}
};
