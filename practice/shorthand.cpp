#include<iostream>
#include<string>

using namespace std;

void printAllShorthands(const string& prefix, string inputStr) {
  cout<<prefix+inputStr<<"\n";

  int maxSkip=inputStr.length()-2;

  for(int i=1;i<=maxSkip;i++) {
    int startPos=1;
    char skipChar='0'+i;
    while(startPos+i-1<inputStr.length()-1) {
      string newPrefix(inputStr, 0, startPos+i);
      newPrefix.replace(startPos, i, 1, skipChar);
      newPrefix = prefix+newPrefix;
      string newInputStr(inputStr, startPos+i, inputStr.length()-startPos-i);
      printAllShorthands(newPrefix, newInputStr);
      startPos+=1;   
    }
  }

  return;

}

void printAllShorthands(string inputStr) {
  printAllShorthands("", inputStr); 
}

int main() {
  printAllShorthands("abcdef"); 
  return 0;
}
