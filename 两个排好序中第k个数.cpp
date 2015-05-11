#include<iostream>
#include<stdlib.h> 
#include<math.h>
using namespace std;
//Notice �� K > 0  
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
      
    //ȡ�м�λ��  
    int aMid = aBeg + (aEnd - aBeg)/2;    
    int bMid = bBeg + (bEnd - bBeg)/2;  
      
    //��A��B�Ŀ�ʼλ�õ����������м�λ�õ�Ԫ�ظ���  
    int halfLen = aMid - aBeg + bMid - bBeg + 2;  
      
    if (A[aMid] < B[bMid])  
    {  
        if (halfLen > k)  
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
  
int main(){
	  const int ALen = 11;  
    const int BLen = 5;  
      
    int apos = 0;  
    int bpos = 0;  
    int A[ALen];  
    int B[ALen];  
      
    //����������������A �� B  
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
      
    //���A��B������  
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
      
    //��֤ÿ��K�ǲ�������  
    for (int i = 1; i <= ALen + BLen; ++i)  
    {  
        cout << i <<" : "<<FindKthElm(A, 0 , ALen - 1, B, 0 , BLen - 1, i)<<endl;  
    }  
      
	return 1;
}
