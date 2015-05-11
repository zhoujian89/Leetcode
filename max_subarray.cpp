#include<iostream>
#include<string.h>
using namespace std;
//[low...mid]  [mid+1...high] 
int find_max_cross_subarray(int A[],int low,int high,int mid){//必须跨越中点 
   int left_sum=INT_MIN;
   int right_sum=INT_MIN;
   int sum=0;
   for(int i=mid;i>=low;i--){
   	sum+=A[i];
   	if(sum>left_sum) left_sum=sum;
   }
   sum=0;
   for(int i=mid+1;i<=high;i++){
   	sum+=A[i];
   	if(sum>right_sum) right_sum=sum;
   }
   return left_sum+right_sum;	
}
//递归查找
int find_max_subarray(int A[],int low,int high){
	if(low==high) return A[low];//low和high相同,只有一个元素,这是基本情况,递归时要写 
	int mid=(low+high)/2;
	int left=find_max_subarray(A,low,mid);
	int right=find_max_subarray(A,mid+1,high);
	int cross=find_max_cross_subarray(A,low,high,mid);
	if(left>=right&&left>=cross)
	return left;
	else if(right>=left&&right>=cross)
	return right;
	else return cross;
} 
int main(){
//	int min=INT_MIN;
//	int max=INT_MAX;
  int A[]={-2,1,-3,4,-1,2,1,-5,4};
  int low=0,high=8;
  cout<<find_max_subarray(A,low,high);
	} 
