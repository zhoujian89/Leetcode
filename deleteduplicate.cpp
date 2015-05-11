 #include<iostream>
using namespace std;
 int removeDuplicates(int A[], int n) {
 	int index=0;
 	if(n==0) return 0;
 	for(int i=0;i<n;){
 		int j=i;
 		while(j<n&&A[j]==A[i]) j++;
 		int num=j-i;
 		if(num==1){
 		A[index]=A[i];
 		index++;
 	}
 	int count=1;
 	if(num>=3){
 		while(count<=2){
 			A[index]=A[i];
 			index++;
 			count++;
 		}
 	}
 	int k=1;
 	if(num==2){
 		while(k<=2){
 			A[index]=A[i];
 			index++;
 			k++;
 		}
 	}
 	i=j;
 	}
     return index;   
    }
    int main(){
	int A[19]={1,1,1,1,1,1,1,1,1,1,1,2,2,3,3,4,4,4,4};
	int len=removeDuplicates(A, 19);
	cout<<"len: "<<len<<endl;
	for(int i=0;i<len;i++){
		cout<<A[i]<<endl;
	}
	return 1;
} 
