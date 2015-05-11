#include<iostream>
#include<string.h>
using namespace std;
int  find_longest_palindrome(char * str){
	bool **p;
	int n=strlen(str);
	p=new bool *[n];
	for(int k=0;k<n;k++){
		p[k]=new bool[n];
	}
	//计算基本情况1 if(i==j) p[i][j]=true;
	
	 for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
    	p[i][j]=false;
    }
     }
     
/*	for(int k=0;k<n;k++) p[k][k]=true;
	for(int k=0;k<n-1;k++) p[k][k+1]=(str[k]==str[k+1]);

	  
    //判断i与j之间的字符串是否回文 
   /* for(int j=n;j>0;j--)
    for(int i=i;j<n;j++){
    		if((i+1<j)&&(j-1>i)){//(i!=j)&&(i+1!=j)&&
    			p[i][j]=(p[i+1][j-1]&&(str[i]==str[j]));
    		}
    	}*/
   /* 	for(int j=n-1;j>=0;j--)
    	for(int i=j;i>=0;i--){
    		if((i+1<j)&&(j-1>i)&&(i<=j)){//(i!=j)&&(i+1!=j)&&
    			p[i][j]=(p[i+1][j-1]&&(str[i]==str[j]));
    	}
    }*/
 /*  for(int d=2;d<=n-1;d++)
   for(int i=0;i<=n-1-d;i++){
   	int j=i+d;
   		//if((i+1<j)&&(j-1>i)){
    			p[i][j]=(p[i+1][j-1]&&(str[i]==str[j]));
    	//}
   }*/ 
//  int num=-1;
	//从状态对角线开始计算
   int num=-1;
   for(int d=0;d<=n-1;d++)//对角线的条数
   for(int i=0;i<=n-1-d;i++){//确定i
   	int j=i+d;
   	if(i==j) p[i][i]=true;
   	else if(i+1==j) p[i][j]=(str[i]==str[j]);
    else p[i][j]=(p[i+1][j-1]&&(str[i]==str[j]));
    if(p[i][j]){
    		if(j-i+1>num) num=j-i+1;
    	//	low=i;
    	//	high=j;
    	} 
   }
    for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
    //	if(p[i][j]){
    //		if(j-i+1>num) num=j-i+1;
    //	} 
    	cout<<p[i][j]<<" ";
    	
    }
    cout<<endl;
     }
     cout<<endl;
     cout<<"num :"<<num;
    
	
} 
int main(){
	char * str="adaiziguizhongrenrnergnohziugiziad";
//	cout<<strlen(str);
//char *str="aaabaabaaa";
//char * str="aabba";
	find_longest_palindrome(str);
} 
