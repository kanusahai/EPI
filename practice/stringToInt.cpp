#include<iostream>
#include<string>
#include<cmath>

using namespace std;

class String {
  private:
  string str;

  public:
  
  String() {
    str="";
  }
 
  String(const string& s) {
    str=s;
  }

  int toInt() {
    bool isNegative=false;
    int retVal=0;
    for(int i=0;i<str.length();i++) {
      if(i==0 && str[i]=='-') {
        isNegative=true;
        continue;
      }
      int digit=str[i]-'0';
      if((!(digit>=0)) || (!(digit<=9)))
        return -99999999;
      retVal+=digit*pow(10,str.length()-1-i);
    }
    if(isNegative)
      retVal*=-1;
    return retVal;
  }
};

int main() {
  string s("-123");
  String str(s);
  cout<<str.toInt()<<endl;
  return 0;
}
