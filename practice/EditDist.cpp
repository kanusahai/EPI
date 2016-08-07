#include <iostream>
#include<string>
using namespace std;

bool isEditDistOne(string& first, string& second) {
	int flag=0;
	
	if(first==second)
		return false;
		
	switch(first.length()-second.length()) {
		case 0:
			for(int i=0;i<first.length();i++) {
				if(first[i]!=second[i]) {
					if(flag==1)
						return false;
					else
						flag=1;
				} 
			}
			return true;
			
		case 1:
			for(int i=0;i<second.length();i++) {
				if(first[i]!=second[i]) {
					while(i<second.length()) {
						if(first[i+1]!=second[i])
							return false;
						i++;
					}
				}
			}
			return true;
		case -1:
			for(int i=0;i<first.length();i++) {
				if(second[i]!=first[i]) {
					while(i<first.length()) {
						if(second[i+1]!=first[i])
							return false;
						i++;
					}
				}
			}
			return true;
		default:
			return false;
	}
}

int main() {
	string first("kanu");
	string second("knuaa");
	if(isEditDistOne(first, second)) 
		cout<<"yay!\n";
	else
		cout<<"noo!\n";
	return 0;
}
