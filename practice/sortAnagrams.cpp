#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

string sortedString(string str) {
  for(int i=0;i<str.length();i++) {
    for(int j=i+1;j<str.length();j++) {
      if(str[i]>str[j]) {
        char temp=str[i];
        str[i]=str[j];
        str[j]=temp;        
      }
    }
  }
  return str;
}

void sortAnagram(string *arr, int n) {
  map<string, vector<string> > hashMap;  
  for(int i=0;i<n;i++) {
    string sortStr= sortedString(arr[i]);
    if(hashMap.find(sortStr)!=hashMap.end()) {
      (hashMap[sortStr]).push_back(arr[i]);
    } else {
      vector<string> vec;
      vec.push_back(arr[i]);
      hashMap[sortStr]=vec;
    }
  }

  map<string,vector<string> >::iterator it;
  int pos=0;
  for(it=hashMap.begin();it!=hashMap.end();it++) {
    for(int i=0;i<(it->second).size();i++) {
      arr[pos]=(it->second)[i];
      pos+=1;
    }
  }
}

void print(string* arr, int n) {
  for(int i=0;i<n;i++) {
    cout<<arr[i];
    cout<<"\n";
  }
}

int main() {
  string arr[]={"hello", "zumba", "elloh", "trevor", "umbaz"};
  sortAnagram(arr, 5);
  print(arr, 5);
  return 0;
}

