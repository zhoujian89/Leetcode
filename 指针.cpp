#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int **p;
	int a[2][2]={1,2,3,4};
//	p=a;
    int (*m)[2];
	m=a;//����ָ���ά�����ָ�� 
	cout<<*(a[0]+1)<<endl; //���������Ԫ�أ�a[0]ָ���һ��Ԫ�أ���ָ���һ��Ԫ�ص�ָ��
	
	for(int i=0;i<2;i++)
	for(int j=0;j<2;j++){
		cout<<*(m[i]+j)<<endl;
		cout<<*(*(m+i)+j)<<endl;
	} 
	return 1;
}
