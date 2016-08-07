#include <iostream>
#include<cstring>

using namespace std;

void insertIntoSpaces(char *str) {
	int len=strlen(str);
	int spaceCount=0;
	for(int i=0;i<len;i++) {
		if(str[i]==' ') 
			spaceCount+=1;
	}
	int newLen=len+2*spaceCount;
	str[newLen]='\0';
	int pos=newLen-1;
	for(int i=len-1;i>=0;i--) {
		if(str[i]==' ') {
			str[pos-2]='%';
			str[pos-1]='2';
 			str[pos]='0';
			pos=pos-3;
		} else {
			str[pos]=str[i];
			pos-=1;
		}
	}
}
int main() {
	char str[]=" a b ";
	insertIntoSpaces(str);
	cout<<str<<"\n";
	return 0;
}
