#include <iostream>  
using namespace std; 

/*���ֲ���*/
int BinarySearch(int A[],int low ,int high,int key){
	int mid=low+(high-low)/2;//��ֹ��� 
	while(low<=high){
		if(A[mid]==key) return mid;
		else if(A[mid]>key) high=mid-1;
		else low=mid+1;
	}
	/*���Ҳ���������whileѭ��*/
	return -1; 
} 

//һ�������ֵ�ȴ�С���������Ӵ�С�ݼ����ҳ�����ֵ
int turningPoint(int A[],int low ,int high){
	int tp=low+(high-low)/2;
	while(tp>low&&tp<high){//ȷ��tp���ǿ�ͷ��Ҳ���ǽ�β
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
