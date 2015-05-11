#include<iostream>
#include<string>
using namespace std;
int countnum(int n) {
	int count=0;
	while(n){
		count++;
		n=n&(n-1);
	}
	return count;
}
int count_num(int n){
	int count=0;
	unsigned int flag = 1;//有局限性 
	while(flag){
		if(n&flag) count++;
		flag=flag<<1;
	}
	return count;
}
int main(){
	cout<<countnum(3)<<endl;
	cout<<count_num(3)<<endl;
	return 1;
}
