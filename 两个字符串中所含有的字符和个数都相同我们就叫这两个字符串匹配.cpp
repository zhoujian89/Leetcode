#include<iostream>
#include<string>
using namespace std;
bool hash(string a,string b){
	int map[256]={0};//≥ı ºªØ 
	for(int i=0;i<a.length();i++){
		map[a[i]]++;	
	}
	for(int i=0;i<b.length();i++){
		map[b[i]]--;
	}
	for(int i=0;i<256;i++){
		if(map[i]==1) return false;
	}
	return true;
	
}
int main(){
	string a="abcdab";
	string b="cdabab";
	cout<<hash(a,b);
	return 1;
}
