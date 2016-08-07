#include<iostream>
#include<stack>
#include<string>
#include<utility>
using namespace std;


void printPerm(string str) {
  stack<pair<string,string>> permStack;

  for(int i=0;i<str.length();i++) {
    pair<string,string> pr;
    char temp=str[0];
    str[0]=str[i];
    str[i]=temp;
    string first(1,str[0]);
    string second(str,1,str.length()-1);
    pr=make_pair(first, second);
    permStack.push(pr);
    str[i]=str[0];
    str[0]=temp;
  }

  while(!permStack.isEmpty()) {
    pair<string,string> pr=permStack.top();
  }

}
