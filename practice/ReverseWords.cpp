#include<iostream>

using namespace std;

class MyString {
  private:
  string str;

  void reverse(int start, int end) {
    if(str.empty() || start>end)
      return;

    while(start<end) {
      char temp=str[start];
      str[start]=str[end];
      str[end]=temp;
      start++;
      end--;
    }
  }

  public:
  MyString(const char *sample) {
    str=sample;
  }

  MyString(const string& str) {
    this->str=str;
  }

  void reverseWords() {
    if(str.empty())
      return;

    int wordBeg=0;
    int wordEnd=0;

    while(wordBeg<str.length() && wordEnd<str.length()) {
      while(str[wordBeg]==' ') {
        wordBeg++;
        if(wordBeg>=str.length())
          return;
      }

      wordEnd=wordBeg+1;
      while(wordEnd<str.length() && str[wordEnd]!=' ')
        wordEnd++;

      wordEnd-=1;
      reverse(wordBeg, wordEnd);
      wordBeg=wordEnd+1;
    }
    return;
  }

  void print() {
    cout<<str<<"\n";
  }
};
int main() {
  MyString ms("My name is Kanu");
  ms.reverseWords();
  ms.print();
  return 0;
}
