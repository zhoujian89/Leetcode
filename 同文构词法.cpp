//Anagrams
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
using namespace std;
vector<string> anagrams(vector<string> &strs) {
	map<string,int> anmap;
	string s;
	vector<string> res;
	for(int i=0;i<strs.size();i++){
		s=strs[i];
		sort(s.begin(),s.end());
		if(anmap.find(s)==anmap.end()){//在hashtable中没有找到 
		anmap[s]=i;//value为strs中序号	
		}
		else{
			if(anmap[s]>=0){//第一次找到
			res.push_back(strs[anmap[s]]);
			anmap[s]=-1;//标记已访问过	
			}
			res.push_back(strs[i]);
		}
	}
	 return res;
} 
/*长度比较函数*/  
int strlonger(char *str1,char *str2)  
{  
return strlen(str1)-strlen(str2)>0;  
}//结果恒大于零  
int main(){
	string s="gagwrnb";
	//对string可以sort排序 
	sort(s.begin(),s.end());
	cout<<s<<endl;
	unsigned int a=67;//为无符号类型 
	unsigned int b=89;
	bool f=(a-b)>0;
	cout<<f<<endl;
	return 1;
}
