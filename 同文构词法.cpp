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
		if(anmap.find(s)==anmap.end()){//��hashtable��û���ҵ� 
		anmap[s]=i;//valueΪstrs�����	
		}
		else{
			if(anmap[s]>=0){//��һ���ҵ�
			res.push_back(strs[anmap[s]]);
			anmap[s]=-1;//����ѷ��ʹ�	
			}
			res.push_back(strs[i]);
		}
	}
	 return res;
} 
/*���ȱȽϺ���*/  
int strlonger(char *str1,char *str2)  
{  
return strlen(str1)-strlen(str2)>0;  
}//����������  
int main(){
	string s="gagwrnb";
	//��string����sort���� 
	sort(s.begin(),s.end());
	cout<<s<<endl;
	unsigned int a=67;//Ϊ�޷������� 
	unsigned int b=89;
	bool f=(a-b)>0;
	cout<<f<<endl;
	return 1;
}
