#include<iostream>
using namespace std;
void smallLarge(int *arr,int *rightMin,int n){
	//rightMin保存右边最小的 
	int leftMax=INT_MIN;
	rightMin[n-1]=arr[n-1];
	for(int i=n-2;i>=0;i--){
		if(rightMin[i+1]>arr[i]){
			rightMin[i]=arr[i];
		}
		else rightMin[i]=rightMin[i+1];
	} 
	for(int i=0;i<n;i++){
	if(arr[i]>=leftMax){
		leftMax=arr[i];
		if(leftMax==rightMin[i])
		cout<<leftMax<<endl; 
	}	
	}
} 
int main(){
	int array[]={7,10,2,6,19,22,32};
	int * rightMin=new int[7];
	smallLarge(array,rightMin,7);
	return 1;
}
