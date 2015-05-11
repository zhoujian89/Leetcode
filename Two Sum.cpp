#include<string> 
#include<iostream>
using namespace std;
int x=0;
int y=0;
void find2sum(int *A,int p,int q,int r,int s){
	int x1=0,x2=0;
for(int i=p;i<=q;i++){
	 x1=A[i];
	for(int j=q+1;j<=r;j++){
	x2=A[j];
	if(x1+x2==s) {
		x=i+1;
		y=j+1;
	}
}
}	
}
void find(int *A,int p,int r,int &s){
	if(p<r){
		int q=(p+r)/2;
		find(A,p,q,s);
		find(A,q+1,r,s);
		find2sum(A,p,q,r,s);
	}
}
int main(){
	int A[]={2, 7, 11, 15};
	int target =17;
	find(A,0,3,target);
	cout<<"x: "<<x<<" y: "<<y<<endl;
	return 1;
}
