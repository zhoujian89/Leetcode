#include<iostream>
#include<stdlib.h> 
#include<math.h>
using namespace std;
int max2(int a,int b){
	if(a>b) return a;
	else return b;
}
int min2(int a,int b){
	if(a<b) return a;
	else return b;
}
int max3(int a,int b,int c){
	if(c>max2(a,b)) return c;
	else return max2(a,b);
}
int min3(int a,int b,int c){
	if(c<min2(a,b)) return c;
	else return min2(a,b);
}
int findproductsubarray(int * A,int n){
	int MIN=A[0];
	int MAX=A[0];
	int a=MAX;
	for(int i=1;i<=n-1;i++){
		int tempmax=MAX*A[i];
		int tempmin=MIN*A[i];
	     MAX=max3(tempmax,tempmin,A[i]);
	     MIN=min3(tempmax,tempmin,A[i]);
	     //cout<<(MIN*A[i])<<" "<<(MAX*A[i])<<" "<<A[i]<<endl;
	     a=max2(a,MAX);
	     //cout<<a<<endl;
	}
	return a;
}
int main(){
	int A[]={-4,-3,-2};
	cout<<findproductsubarray(A,3)<<endl;
	return 1;
} 
