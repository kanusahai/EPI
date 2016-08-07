#include <iostream>
#include<cstring>
using namespace std;

bool isSubstring(char *s1, char* s2) {
	if(strstr(s1,s2)!=NULL)
		return true;
	else
		return false;
}
bool isRotation(char *s1, char *s2) {	
	strcat(s1,s1);		
	if(isSubstring(s1, s2)) {
		return true;
	} else {
		return false;
	} 
	
}
int main() {
	char s1[40]="waterbottle";
	char s2[40]="erbottlewat";
	if(isRotation(s1,s2)) 	
		cout<<"yay!";
	else
		cout<<"no";
	return 0;
}
