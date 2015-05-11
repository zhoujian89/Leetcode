#include<string> 
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int main(){
	char A[]={'5','6'};
	string a=A;
	cout<<a<<endl;
	int i=0;
    i=atoi(A);
	cout<<i<<endl;
	int m=12;
	char B[1000];
	itoa(m,B,2);
	string s=B;
	cout<<s<<endl;
	return 1;
} 
