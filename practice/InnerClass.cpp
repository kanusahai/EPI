#include<iostream>

using namespace std;


class Test {
  private :

  static int count;

  class InnerClass {
    public :
    int count;
    InnerClass() {
      count=7;
    }
    void printCount() {
      cout<<"InnerClass count: "<<count<<"\n";
    }

  };

  public:
  Test() {
    count+=1;
  }

  InnerClass* getInstance() {
        return new InnerClass();
  }
  void increment() {
    count+=1;
  }

  static void printCount() {
    cout<<count<<"\n";
  }

};

int Test::count = 0;

int main() {
  Test t;
  InnserClass *i=t.getInstance();  
  return 0;
}
