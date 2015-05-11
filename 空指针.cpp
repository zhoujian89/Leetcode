#include<iostream>
#include<string>
using namespace std;
int main(){
	//int·¶Î§  
	short  *p;
	cout<<*p<<endl; 
	while(1){
		cout<<*p+1<<endl;
		*p=*p+1;
		if(*p==30000) break;
	//	if(*p==0) break;
	}
	return 1;
} 
