#include<iostream>
#include<assert.h>
using namespace std;
char *strcpy(char *strDest,char *strSrc){
	assert((strDest!=NULL) && (strSrc!=NULL));//���ԣ��������㣬�����˳������� 
	char *address=strDest;
	while((*strDest++=*strSrc++)!='\0');
	return address;
} 
int main(){
	return 1;
} 
