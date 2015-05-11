#include<iostream>
using namespace std;
  int removeDuplicates(int A[], int n) {
  	int count=n-1;
  	for(int i=0;i<count;i++){
  		int temp=A[i];
  		int t=i+1;
  	while(t<=count&&A[t]==temp){
  		cout<<count+1<<endl;
		int k=t+1;
		//没有可移动的元素 
		if(count-k+1==0) {
  	    count--;
  	    cout<<"ddd"<<endl;
  		}
  		//有可移动元素，前移一位 
  		else{
		  for(int j=k;j<=count;j++){
		  A[j-1]=A[j];
  			 }
  			count--; 
  		}
  			
		}
  		
  	}
  	return count+1;
        
    }
int main(){
	int A[]={-999,-999,-998,-998,-997,-997,-996,-996,-995,-995,-994,-994,-993,-993,-992,-992};
	int len=removeDuplicates(A,16);
	for(int i=0;i<len;i++){
		cout<<"A: "<<A[i]<<endl;
	}
	return 1;
}
