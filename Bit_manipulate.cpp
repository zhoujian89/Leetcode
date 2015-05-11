#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
 int singleNumber(int A[], int n) {
        /*用异或实现*/
        int x=0;
        for(int i=0;i<n;i++){
        	x=x^A[i];
        }
		return x; 
    }
    int singleNumber2(int A[], int n) {
    	const int M=sizeof(int)*8;
    	int count[M];//记录int每一位二进制出现的次数
    	fill(count,count+M,0);
		for(int i=0;i<n;i++)
		for(int j=0;j<M;j++){
			count[j]+=(A[i]>>j)&1;//A[i]右移j位，再和1相与 
			count[j]=count[j]%3; 
		} 
		int result=0;
		for(int i=0;i<M;i++){
			result+=(count[i]<<i);
		}
		return result;
        
    }
int main(){
	int x=12345;
	int y=0^x;
	int A[5]={11,123,11,22,22};
	int B[7]={2,2,2,4,5,5,5};
	int result=0;
	int count[3]={1,0,1};
	cout<<y<<endl;
	cout<<singleNumber2(A,5)<<endl;
	cout<<singleNumber2(B,7)<<endl;
	
for (int i = 0; i < 3; i++) {
result += (count[i] << i);
}
cout<<result<<endl;
	return 1;
} 
