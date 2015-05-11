#include<iostream>
#include<stdlib.h> 
#include<math.h>
using namespace std;
int FindKthElm(int A[], int aBeg, int aEnd, int B[], int bBeg, int bEnd, int k)   
{
	if(aBeg>aEnd){
		return B[bBeg+k-1];
	}
	if(bBeg>bEnd){
		return A[aBeg+k-1];
	}
	int aMid=aBeg+(aEnd-aBeg)/2;// (aBeg+aEnd)/2;
	int bMid=bBeg+(bEnd-bBeg)/2;//(bBeg+bEnd)/2;
	int half=aMid-aBeg+bMid-bBeg+2;
	if(A[aMid]>B[bMid]){// 
		if(half>k) return FindKthElm(A,aBeg,aMid-1,B,bBeg,bEnd,k);
		else return FindKthElm(A,aBeg,aEnd,B,bMid+1,bEnd,k-(bMid-bBeg+1)); 
	}
	else {
		if(half>k) return FindKthElm(A,aBeg,aEnd,B,bBeg,bMid-1,k);
		else return FindKthElm(A,aMid+1,aEnd,B,bBeg,bEnd,k-(aMid-aBeg+1));
		
	}
	} 
int main(){
	const int ALen = 11;  
    const int BLen = 5;  
      
    int apos = 0;  
    int bpos = 0;  
    int A[ALen];  
    int B[ALen];  
      
    //生成两个递增数组A 和 B  
    for (int i = 1; i <= ALen + BLen; ++i)  
    {  
        if (apos >= ALen)  
        {  
            B[bpos++] = i;  
        }  
        else if (bpos >= BLen)  
        {  
            A[apos++] = i;  
        }  
        else  
        {  
            if (rand()%2 == 1)  
            {  
                A[apos++] = i;  
            }  
            else  
            {  
                B[bpos++] = i;  
            }  
        }  
    }  
      
    //输出A和B的内容  
    for (int i = 0; i < ALen; ++i)  
    {  
        cout <<A[i] <<" ";  
    }  
    cout <<endl;  
    for (int i = 0; i < BLen; ++i)  
    {  
        cout <<B[i] <<" ";  
    }  
    cout <<endl;  
      
    //验证每个K是不是正解  
    for (int i = 1; i <= ALen + BLen; ++i)  
    {  
        cout << i <<" : "<<FindKthElm(A, 0 , ALen - 1, B, 0 , BLen - 1, i)<<endl;  
    }  
	return 1;
}
