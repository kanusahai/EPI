#include<iostream>

using namespace std;

class MyString {
  private:
  string str;
  int len;

  void printAllPerm(int start, int end) {
    if(start==end) {
      cout<<this->str<<"\n";
      return;
    }
    int hashSet[26];
    for(int i=0;i<26;i++)
      hashSet[i]=0;

    char temp=str[start];
    for(int i=start;i<=end;i++) {
      int val=str[i]-'a';
      if(hashSet[val]==1)
        continue;
      hashSet[val]=1;
      str[start]=str[i];
      str[i]=temp;

      printAllPerm(start+1, end);

      str[i]=str[start];
      str[start]=temp; 
    }
  }
  public:
  MyString(const string& str) {
    this->str=str;
    len=str.length();
  }

  void printAllPerm() {
    if(!str.empty()) {
      printAllPerm(0, str.length()-1);
    }
  }

};


int main() {
  MyString ms("aab");
  ms.printAllPerm();
  return 0;
}
