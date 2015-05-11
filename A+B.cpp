#include<iostream>
using namespace std;
char * add(int a,int b){
	char * p=(char *)a;
	return &p[b];
}
int main(){
	cout<<add(3,5)<<endl;
	return 1;
}
