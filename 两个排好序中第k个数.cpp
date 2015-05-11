#include<iostream>
#include<stdlib.h> 
#include<math.h>
using namespace std;
//Notice ： K > 0  
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
      
    //取中间位置  
    int aMid = aBeg + (aEnd - aBeg)/2;    
    int bMid = bBeg + (bEnd - bBeg)/2;  
      
    //从A和B的开始位置到两个数组中间位置的元素个数  
    int halfLen = aMid - aBeg + bMid - bBeg + 2;  
      
    if (A[aMid] < B[bMid])  
    {  
        if (halfLen > k)  
        {  
            // 此时在合并的数组中A[aBeg...aMid]和元素一定在B[bMid]的左侧，  
            // 即此时第k大的元素一定比B[bMid]这个元素小（严格来说不大于）  
            // 故以后没有必要搜索 B[bMid...bEnd]这些元素  
            return FindKthElm(A, aBeg, aEnd, B, bBeg, bMid-1, k); // - 1 
        }  
        else  
        {  
            // 此时在合并的数组中A[aBeg...aMid]元素一定在B[bMid]的左侧，  
            // 所以前K个元素中一定包含A[aBeg...aMid]（可以使用反证法来证明这点）。  
            // 但是无法判断A[amid+1...aEnd]与B[bBeg...bEnd]之间的关系，帮需要对他们进行判断  
            // 此时K就剩下除去A[aBeg...aMid]这些元素，个数为k - (aMid - aBeg + 1)  
            return FindKthElm(A, aMid + 1, aEnd, B, bBeg, bEnd, k - (aMid - aBeg + 1));  
        }  
    }  
    else  
    {  
        //注释与上面相似  
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
