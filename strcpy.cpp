#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int main(){
	char s[]="123456789";
	char d[]="123456";
	strcpy(d,s);
	printf("%d, %d",&d,&s);
    //cout<<d<<endl;
    //cout<<s;
    
	return 1;
}
