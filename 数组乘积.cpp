#include<iostream>
using namespace std;
int *cal(int * input,int n){
	int * result=new int[n];
	result[0]=1;
	for(int i=1;i<n;i++){
		result[i]=result[i-1]*input[i-1];
	}
	result[0]=input[n-1];
	for(int j=n-2;j>0;j--){
		result[j]=result[j]*result[0];
		result[0]=result[0]*input[j];
	}
	return result;
}
int main(){
	int input[]={2,3,4,5};
	int *result=cal(input,4);
	for(int i=0;i<4;i++){
		cout<<result[i]<<" ";
	}
	cout<<endl;
	//cout<<INT_MAX;
	return 0;
} 
