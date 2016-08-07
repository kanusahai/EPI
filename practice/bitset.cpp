#include<iostream>
#include<bitset>

using namespace std;

int main() {
  bitset<12> bits;
  bits[0]=1;

  cout<<sizeof(int)<<"\n"<<sizeof(bits)<<"\n";

  return 0;

}
