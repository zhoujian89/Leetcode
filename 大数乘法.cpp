#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
string multiply1(string num1, string num2) {
  /*      int len1=num1.size();
        int len2=num2.size();
        string result="";
        int * s=new int[len1+len2];
        for(int k=0;k<len1+len2;k++) s[k]=0;
        for(int i=0;i<len1;i++)
        for(int j=0;j<len2;j++)
        s[i+j+1]+=(num1[i]-'0')*(num2[j]-'0');
        
        for(int i=len1+len2-1;i>=0;i--){
            if(s[i]>=10){
                s[i-1]+=s[i]/10;
                s[i]%=10;
            }
        }
        for(int k=0;k<len1+len2;k++) cout<<s[k]<<endl; 
        int i=0,j=0;
        while(s[i]==0) i++;
        cout<<i<<endl;
        if(i==len1+len2) return "0";
        for(;i<len1+len2;i++,j++) {
            char temp=s[i]+'0';
           // cout<<s[i]<<endl;
            result.insert(j,&temp);
        }
        cout<<result<<endl;
        return result;*/
         int len1=num1.size();
        int len2=num2.size();
        string result="";
        int * s=new int[len1+len2];
        for(int i=0;i<len1+len2;i++) s[i]=0;
        for(int i=0;i<len1;i++)
        for(int j=0;j<len2;j++)
        s[i+j+1]+=(num1[i]-'0')*(num2[j]-'0');
        for(int i=len1+len2-1;i>=0;i--){
            if(s[i]>=10){
                s[i-1]+=s[i]/10;
                s[i]%=10;
            }
        }
        for(int k=0;k<len1+len2;k++) cout<<s[k]<<endl; 
        int i=0,j=0;
        while(s[i]==0) i++;
        cout<<"i : "<<i<<endl;
        cout<<len1+len2<<endl;
        if(i==len1+len2) return "0";
        for(;i<len1+len2;i++,j++) {
            char temp=s[i]+'0';
           // result.insert(j,&temp);
           result.push_back(temp);
        }
        return result;
        
    }
void multipy(const char *a,const char *b){
	int ca,cb,*s;
	ca=strlen(a);
	cb=strlen(b);
	s=(int *)malloc(sizeof(int)*(ca+cb));
	for(int i=0;i<ca+cb;i++) s[i]=0;
	//从高位开始计算 
	for(int i=0;i<ca;i++)
	for(int j=0;j<cb;j++){
		s[i+j+1]+=(a[i]-'0')*(b[j]-'0');
	}
	//移位运算，从低位开始
	for(int i=ca+cb-1;i>=0;i--){
		if(s[i]>=10){
		s[i-1]+=s[i]/10;//高位进位 
		s[i]=s[i]%10;
		} 
	} 
	char *c=(char *)malloc(sizeof(char)*(ca+cb));
	int i=0,j=0;
	while(s[i]==0) i++;

	for(j=0;i<ca+cb;i++,j++)c[j]=s[i]+'0';
	c[j]='\0';
	for(i=0;i<ca+cb;i++) cout<<c[i];
//	cout<<c<<endl;
	free(s);
	free(c);	
}
int main(){
	const char * a="123";
	const char * b="456";
	string aa="1";
	string bb="1";
//	multipy(a,b);
    cout<<multiply1(aa,bb);
	return 1;
}
