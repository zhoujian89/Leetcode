#include<iostream>
#include<assert.h>
using namespace std;
char *strcpy(char *strDest,char *strSrc){
	assert((strDest!=NULL) && (strSrc!=NULL));//¶ÏÑÔ£¬Èô²»Âú×ã£¬³ÌĞòÍË³ö£¬±¨´í 
	char *address=strDest;
	while((*strDest++=*strSrc++)!='\0');
	return address;
} 
int main(){
	return 1;
} 
