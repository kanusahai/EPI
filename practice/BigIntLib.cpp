#include<iostream>
#include<string>
using namespace std;



class BigNum {

  private:
  string num;

  int* createArr(string str) {
    int *arr=new int[str.length()];
    for(int i=0;i<str.length();i++) {
      arr[i]=str[i]-'0';
    }
    return arr;
  }

  string createStr(int* arr, int len) {
    string result="";
    for(int i=0;i<len;i++) {
      result+='0'+arr[i];
    }
    return result;
  }

  string prodSingleDigit(string numA, int digit) {
    int* arr=createArr(numA);
    int* resultArr=new int[numA.length()];
    int carry=0;
    for(int i=numA.length()-1;i>=0;i--) {
      int val=(arr[i]*digit)+carry;
      resultArr[i]=val%10;
      carry=val/10;      
    }
    string result=createStr(resultArr, numA.length());
    if(carry>0) {
      char prefix='0'+carry;
      return prefix+result;
    } else 
      return result;
  }

  public:
  BigNum(string num) {
    this->num=num;
  }

  void sum(string numB) {
    int *arrA=createArr(num);
    int *arrB=createArr(numB);

    int lenA=num.length();
    int lenB=numB.length();
    int newLen=(lenA>=lenB)?lenA:lenB;

    int* resultArr=new int[newLen];
    
    int i=lenA-1;
    int j=lenB-1;
    int k=newLen-1;
    int carry=0;

    while(i>=0 && j>=0) {
      int val=arrA[i]+arrB[j]+carry;
      resultArr[k]=val%10;
      carry=val/10;

      i-=1;
      j-=1;
      k-=1;
    }

    while(i>=0) {
      resultArr[k]=(arrA[i]+carry)%10;
      carry=(arrA[i]+carry)/10;
      i-=1;
      k-=1;
    }
    while(j>=0) {
      resultArr[k]=(arrB[j]+carry)%10;
      carry=(arrB[j]+carry)/10;
      j-=1;
      k-=1;
    }

    string result=createStr(resultArr, newLen);
    if(carry>0) {
      char prefix='0'+carry;
      this->num=prefix+result;
    } else {
      this->num=result;
    }

  }

  void product(string numB) {
    int* arrB=createArr(numB);
    int lenB=numB.length();

    BigNum answer("0");
    string suffix="";
    for(int i=lenB-1;i>=0;i--) {
      int digit=arrB[i];
      string partAns=prodSingleDigit(this->num, digit);
      partAns+=suffix;
      suffix+="0";
      answer.sum(partAns);
    }

    this->num=answer.getNum();
  }

  string getNum() {
    return num;
  }
  void print() {
    cout<<num<<"\n";
  }
};


int main() {
  BigNum bn("0");
  bn.sum("9999");
  bn.print();

  bn.product("4");
  bn.print();
  return 0;
}
