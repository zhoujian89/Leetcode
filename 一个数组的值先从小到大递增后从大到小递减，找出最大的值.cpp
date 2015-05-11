#include <iostream>  
using namespace std; 

/*二分查找*/
int BinarySearch(int A[],int low ,int high,int key){
	int mid=low+(high-low)/2;//防止溢出 
	while(low<=high){
		if(A[mid]==key) return mid;
		else if(A[mid]>key) high=mid-1;
		else low=mid+1;
	}
	/*查找不到，跳出while循环*/
	return -1; 
} 

//一个数组的值先从小到大递增后从大到小递减，找出最大的值
int turningPoint(int A[],int low ,int high){
	int tp=low+(high-low)/2;
	while(tp>low&&tp<high){//确保tp不是开头，也不是结尾
	if(A[tp]>A[tp-1]&&A[tp]>A[tp+1]) return tp;
	else if(A[tp]<A[tp-1]) {
		high=tp-1;
		tp=low+(high-low)/2;
	}
	else {
		low=tp+1;
		tp=low+(high-low)/2;
	}	
	}
	return -1;
}
int main(){
	int A[]={2,3,4,5,8,7,2,3,4};
	cout<<turningPoint(A,0,8);
	return 1;
} 
