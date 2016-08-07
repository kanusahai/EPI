#include<iostream>
#include<string>
#include<map>
#include<vector>

using namespace std;

void findAllPossiblePerm(vector<string> &vec, string baseStr, int pos) {
  if(pos==baseStr.length()) {
    vec.push_back(baseStr);
    return;
  }

  int charHash[26]={};

  for(int i=pos;i<baseStr.length();i++) {
    int val=baseStr[i]-'a';
    if(charHash[val]==1)
      continue;

    charHash[val]=1;
    char temp=baseStr[i];
    baseStr[i]=baseStr[pos];
    baseStr[pos]=temp;

    findAllPossiblePerm(vec, baseStr, pos+1);
    baseStr[pos]=baseStr[i];
    baseStr[i]=temp;
    
  } 

}

void printAllPalindromic(string str) {
  if(str.length()==0)
    return;
  map<char,int> freqMap;
  map<char,int>::iterator it;
  for(int i=0;i<str.length();i++) {
    it=freqMap.find(str[i]);
    if(it!=freqMap.end())
      freqMap[str[i]]+=1;
    else
      freqMap[str[i]]=1;  
  }  
  bool flag=false;
  char chr='\0';
  string baseStr="";
  for(it=freqMap.begin();it!=freqMap.end();it++) {
    if(it->second%2!=0) {
      if(flag==false) {
        flag=true;
        chr=it->first;
      } else
        return;
    }
    
    baseStr.append((it->second)/2,it->first);
    
  }

  
  vector<string> vec;

  findAllPossiblePerm(vec, baseStr,0);

  if(!vec.empty()) {
    for(int i=0;i<vec.size();i++) {
      string validPerm=vec[i];
      if(chr!='\0')
        validPerm+=chr;
  
      for(int j=vec[i].length()-1;j>=0;j--) {
        validPerm.append(1,(vec[i]).at(j));
      }
      cout<<validPerm<<"\n";
    }
  } else {
    cout<<"Auxilliary function didn't work\n";
  }

}

int main() {
  printAllPalindromic("ggeei");
  return 0;
}
