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
	m=a;//声明指向二维数组的指针 
	cout<<*(a[0]+1)<<endl; //访问数组的元素，a[0]指向第一行元素，是指向第一行元素的指针
	
	for(int i=0;i<2;i++)
	for(int j=0;j<2;j++){
		cout<<*(m[i]+j)<<endl;
		cout<<*(*(m+i)+j)<<endl;
	} 
	return 1;
}
