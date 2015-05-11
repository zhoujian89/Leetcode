#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int lengthOfLastWord(const char *s) {
  int size=strlen(s)-1;
  if(size==-1||size==0) return 0;
  const char *p=s+size;
  int count=0;
  while(*p!=' '&&p>=s){
  	p--;
  	count++;
  }
  if(count==size) count=0;
  return count;
}
int main(){
	char *s="Hello World";
	int len=lengthOfLastWord(s);
	cout<<len;
	return 1;
}
