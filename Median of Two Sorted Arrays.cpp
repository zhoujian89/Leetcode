#include <iostream>  
using namespace std; 
	 int FindKthElm(int A[], int aBeg, int aEnd, int B[], int bBeg, int bEnd, int k)  
{  
 
    if (aBeg > aEnd)  
    {  
        return B[bBeg + k - 1];  
    }  
    if (bBeg > bEnd)  
    {  
        return A[aBeg + k - 1];  
    }  
      
    //ȡ�м�λ�� ;�м�λ�ò�ҪдΪ(aEnd+aBeg)/2�������������������int��Χ 
    int aMid = aBeg + (aEnd - aBeg)/2;    
    int bMid = bBeg + (bEnd - bBeg)/2;  
      
    //��A��B�Ŀ�ʼλ�õ����������м�λ�õ�Ԫ�ظ���  
    int halfLen = aMid - aBeg + bMid - bBeg + 2;  
      
    if (A[aMid] < B[bMid])  
    {  
        if (halfLen >k)  
        {  
            // ��ʱ�ںϲ���������A[aBeg...aMid]��Ԫ��һ����B[bMid]����࣬  
            // ����ʱ��k���Ԫ��һ����B[bMid]���Ԫ��С���ϸ���˵�����ڣ�  
            // ���Ժ�û�б�Ҫ���� B[bMid...bEnd]��ЩԪ��  
            return FindKthElm(A, aBeg, aEnd, B, bBeg, bMid-1, k); // - 1 
        }  
        else  
        {  
            // ��ʱ�ںϲ���������A[aBeg...aMid]Ԫ��һ����B[bMid]����࣬  
            // ����ǰK��Ԫ����һ������A[aBeg...aMid]������ʹ�÷�֤����֤����㣩��  
            // �����޷��ж�A[amid+1...aEnd]��B[bBeg...bEnd]֮��Ĺ�ϵ������Ҫ�����ǽ����ж�  
            // ��ʱK��ʣ�³�ȥA[aBeg...aMid]��ЩԪ�أ�����Ϊk - (aMid - aBeg + 1)  
            return FindKthElm(A, aMid + 1, aEnd, B, bBeg, bEnd, k - (aMid - aBeg + 1));  
        }  
    }  
    else  
    {  
        //ע������������  
        if (halfLen > k)  
        {  
            return FindKthElm(A, aBeg, aMid-1, B, bBeg, bEnd, k);  // - 1
        }  
        else  
        {  
            return FindKthElm(A, aBeg, aEnd, B, bMid + 1, bEnd, k - (bMid - bBeg + 1));  
        }  
    }  
}  
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if((m+n)%2==1)
        return FindKthElm(A,0,m-1,B,0,n-1,(m+n)/2+1);
        else  {
            double left=FindKthElm(A,0,m-1,B,0,n-1,(m+n)/2);
            //cout<<(m+n)/2-1<<endl;
            double right=FindKthElm(A,0,m-1,B,0,n-1,(m+n)/2+1);
            cout<<"right: "<<right<<" left: "<<left<<endl;
            return (right+left)/2;
        }
        
    }
    int main(){
    	int A[]={};
    	int B[2]={2,3};
    	cout<<findMedianSortedArrays(A, 0, B, 2)<<endl;
    }
