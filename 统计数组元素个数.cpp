#include<string> 
#include<iostream>
using namespace std;
void calculate(int A[],int n){
	//A数组元素范围 1..n
	for(int i=0;i<n;i++){
		A[A[i]%n]+=n;
	} 
	for(int i=0;i<n;i++){
		A[i]=A[i]/n;
		cout<<"frequent: "<<A[i]<<endl; 
	}
} 
int main(){
	int * A;
	int n;
	cout<<"元素个数："<<endl;
	cin>>n;
	cout<<endl;
	A=new int[n];
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	calculate(A,n);
} 
