#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main(){
	map<int ,int> m;
	map<int,int>::iterator iter;
	int target=0;
	int num[4]={0, 4, 3, 0};
	int n=4;
	vector<int> ans;
	/*map����<key,value>�ķ�ʽ*/                       
	/*m[5]=6;
	m[6]=7;
	m[5]=9;
	m.insert(map<int,int>::value_type(9,10));
	for(iter=m.begin();iter!=m.end();iter++){
		cout<<"key : "<<iter->first<<" value: "<<iter->second<<endl; 
	} */
	for(int i=0;i<n;i++){
		iter=m.find(target-num[i]);
		//û���ҵ� 
		if(iter==m.end()){
			m.insert(map<int,int>::value_type(num[i],i+1)); 
		} 
		else{
			ans.push_back(iter->second);
			ans.push_back(i+1);
			break;
		}
	} 
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" "<<endl;
	}
	
	return 1;
} 
