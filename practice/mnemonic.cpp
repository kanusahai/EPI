#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<stack>
using namespace std;


class Mnemonic {

  private:
  map<int,string> keypad;

  public:
  Mnemonic(const map<int,string>& kp) {
    keypad=kp;
  }

  void printKeypad() {
    map<int,string>::iterator it;
    for(it=keypad.begin();it!=keypad.end();it++) {
      cout<<it->first<<" "<<it->second<<"\n";
    }
  }

  vector<string> allMnemonics(int *number, int len) {
    stack<string> st;
    

  }
};

int main() {
  map<int,string> kp;
  kp[2]="abc";
  kp[3]="def";
  

  Mnemonic mn(kp);
  mn.printKeypad();
  return 0;
  
}


