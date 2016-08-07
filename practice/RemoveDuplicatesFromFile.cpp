#include<iostream>
#include<string>
#include<fstream>
#include<map>
using namespace std;


class FileContent {
  private:
  ifstream ifs;
  std::string content;
  map<int,int> hashMap;

  int hash(string str) {
    int hashVal=0;
    for(string::const_iterator it=str.begin(); it!=str.end();it++) {
      hashVal+=*it;
    }

    return hashVal;
  }

  public:

  FileContent(const char* location) {
    ifs.open(location);
  }
  
  
  void removeDup() {
    string temp;
    int hashVal;
    while(getline(ifs,temp)) { //Instead of reading lines, read the whole file and tokenize sentences. Iterate over each sentence
      hashVal = hash(temp);
      map<int,int>::iterator it = hashMap.find(hashVal);
      if(it==hashMap.end()) {
        content+=temp; //Add full stops
      }
    }
  }

  void printContent() {
    cout<<content;
  }

};

int main() {

  return 0;
}
