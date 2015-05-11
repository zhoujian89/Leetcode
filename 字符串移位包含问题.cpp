#include<iostream>
#include<string.h>
using namespace std;
bool find(const char *dest, const char * src){
	int lensrc=strlen(src);
	int lendest=strlen(dest);
	cout<<lensrc<<" "<<lendest<<endl;
	if(lendest>lensrc) return false;
	int k;
	for(int i=0;i<lensrc;i++){
		int k=i;
		for(int j=0;j<lendest;j++){
			if(src[(k++)%lensrc]!=dest[j]){
					cout<<"fff"<<endl;
					break;
			} 
		}
		if(k-i==lendest) return true;
	
	}
	cout<<k<<endl;
	return false;
} 
int main(){
	char * s1="AABCD";
	char * s2="CDAA";
	string s="aaa";
	s+="b";
	cout<<s<<endl;
	cout<<s.substr(0,2)<<endl;
	cout<<find(s2,s1)<<endl;
	return 1;
}
