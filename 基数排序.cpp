#include<iostream>
#include<malloc.h>
using namespace std;

int getdigit(int x,int d)  
{   
    int a[] = {1, 1, 10};     //��Ϊ���������������Ҳֻ����λ���������ڴ�ֻ��Ҫ��ʮλ������
    return ((x / a[d]) % 10);    //ȷ��Ͱ��
}  

void  PrintArr(int ar[],int n)
{
    for(int i = 0; i < n; ++i)
        cout<<ar[i]<<" ";
    cout<<endl;
}

void msdradix_sort(int arr[],int begin,int end,int d)  
{     
    const int radix = 10;   
    int count[radix], i, j; 
    //�ÿ�
    for(i = 0; i < radix; ++i)   
    {
        count[i] = 0;   
    }
    //����Ͱ�洢�ռ�
    int *bucket = (int *) malloc((end-begin+1) * sizeof(int));    
    //ͳ�Ƹ�Ͱ��Ҫװ��Ԫ�صĸ���  
    for(i = begin;i <= end; ++i)   
    {
        count[getdigit(arr[i], d)]++;   
    }
    //���Ͱ�ı߽�������count[i]ֵΪ��i��Ͱ���ұ߽�����+1
    for(i = 1; i < radix; ++i)   
    {
        count[i] = count[i] + count[i-1];    
    }
    //����Ҫ��������ɨ�裬��֤�����ȶ��� 
    for(i = end;i >= begin; --i)          
    {    
        j = getdigit(arr[i], d);      //����ؼ���ĵ�dλ�����֣� ���磺576�ĵ�3λ��5   
        bucket[count[j]-1] = arr[i];   //�����Ӧ��Ͱ�У�count[j]-1�ǵ�j��Ͱ���ұ߽�����   
        --count[j];                    //��j��Ͱ����һ��Ԫ�ص�λ��(�ұ߽�����+1)   
    }   
    //ע�⣺��ʱcount[i]Ϊ��i��Ͱ��߽�    
    //�Ӹ���Ͱ���ռ�����  
    for(i = begin, j = 0;i <= end; ++i, ++j)  
    {
        arr[i] = bucket[j]; 
    }       
    //�ͷŴ洢�ռ�
    free(bucket);   
    //�Ը�Ͱ�����ݽ���������
    for(i = 0;i < radix; i++)  
    {   
        int p1 = begin + count[i];         //��i��Ͱ����߽�   
        int p2 = begin + count[i+1]-1;     //��i��Ͱ���ұ߽�   
        if(p1 < p2 && d > 1)  
        {
            msdradix_sort(arr, p1, p2, d-1);  //�Ե�i��Ͱ�ݹ���ã����л���������λ�� 1    
        }
    }  
} 

int  main()
{
    int  ar[] = {12, 14, 54, 5, 6, 3, 9, 8, 47, 89};
    int len = sizeof(ar)/sizeof(int);
    cout<<"����ǰ�������£�"<<endl;
    PrintArr(ar, len);
    msdradix_sort(ar, 0, len-1, 2);
    cout<<"����������£�"<<endl;
    PrintArr(ar, len);
    return 1;
} 
/*
����ǰ�������£�
12 14 54 5 6 3 9 8 47 89
����������£�
3 5 6 8 9 12 14 47 54 89
 */
