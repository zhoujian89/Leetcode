#include<string> 
#include<iostream>
using namespace std;
void calculate(int A[],int n){
	//A����Ԫ�ط�Χ 1..n
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
	cout<<"Ԫ�ظ�����"<<endl;
	cin>>n;
	cout<<endl;
	A=new int[n];
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	calculate(A,n);
} 
