/*Given an implementation of Stack data structure, implement a new Stack class that stores only integers and can also return MaxValue in the stack in O(1). Other stack operations such as: Peek, Push, Pop should also be O(1).

swamipat@microsoft.com


OriginalStack: 5, 4, 7
OriginalStack: -, -, ?  --> the MaxVal is indeed the actual value to return and also help you to calculate the n

MaxVal=        5, 5, 7
*/

#include<iostream>
#include<stack>

using namespace std;

class MaxStack {
    private:
    stack<int> originalStack;
    stack<int> maxSoFar;

    public:
    MaxStack() {
    
    }
    
    void push(int val) {
        originalStack.push_back(val);
        int curMax=maxSoFar.top();
        if(val>=curMax) {
           maxSoFar.push_back(val); 
        }
    }
    
    int pop() {
        int retVal=originalStack.top();
        originalStack.pop();
        if(retVal==maxSoFar.top()) {
            maxSoFar.pop();
        }
        return retVal;
    }
    
    int getMax() {
        return maxSoFar.top();
    }

};
