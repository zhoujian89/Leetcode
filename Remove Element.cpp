 #include<iostream>
using namespace std;
 int removeElement(int A[], int n, int elem) {
        int index=0;
        for(int i=0;i<n;i++){
        	if(A[i]!=elem){
        		A[index]=A[i];
        		index++;
        	}
         
        }
        return index;
    }
int main(){
	int A[19]={1,1,1,1,1,1,1,1,1,1,1,2,2,3,3,4,4,4,4};
	int len=removeElement(A, 19,4);
	cout<<"len: "<<len<<endl;
	for(int i=0;i<len;i++){
		cout<<A[i]<<endl;
	}
	return 1;
}
