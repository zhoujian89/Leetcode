#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int> > subsetsWithDup(vector<int> &S) {
	vector<vector<int> > ans;
	sort(S.begin(),S.end());
	ans.push_back(vector<int>());
	for(int i=0;i<S.size();){
		int j=i;
		//找到重复的 
		while(j<S.size()&&S[i]==S[j]) j++;
		int size=ans.size();//上一次处理好的ans元素个数 
		//处理重复的，没有重复元素，len=1 总共有j-i个元素要处理 
		for(int len=1;len<=j-i;len++) {
			
			for(int k=0;k<size;k++){
				//找到上次处理好的结果，每个集合都要考虑 
				vector<int> temp(ans[k]);
				//加入S[i],对上次结果的所有集合，加入重复的len个S[i] 
				for(int m=0;m<len;m++) temp.push_back(S[i]);
				ans.push_back(temp);
			}
			
		}
		//下次从j开始 
		i=j;
	}
	return ans;
	
}
int main(){
	vector<int> S;
	S.push_back(1);
	S.push_back(2);
	S.push_back(2);
	vector<vector<int> >  v=subsetsWithDup(S);
	for(int i=0;i<v.size();i++){
	for(int j=0;j<v[i].size();j++){
		cout<<v[i][j]<<" ";
	} 
	cout<<endl;
		}
	return 1; 
}
