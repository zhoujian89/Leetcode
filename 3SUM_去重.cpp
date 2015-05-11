#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int> > threeSum(vector<int> &num) {
	vector<vector<int> > ans;
	//先固定一个元素num[i],然后设两个指针，满足num[i]+num[p]+num[q]=0即可 
	for(int i=0;i<num.size()&&num[i]<=0;){
	int j=i;
	//保证没有重复的num[i] 
	while(j<num.size()&&num[j]==num[i]) j++;
	int p=i+1;
	int q=num.size()-1;
	//收缩法找另外两个元素 
	while(p<q){
		//找到等于0 
		if(num[i]+num[p]+num[q]==0){
			vector<int> temp;
			temp.push_back(num[i]);
			temp.push_back(num[p]);
			temp.push_back(num[q]);
			ans.push_back(temp);
			//对p,q去重
			while(p++<q&&num[p]==num[p-1]) {
			}
			while(q-->p&&num[q]==num[q+1]) {
			}
			
		}
		else if(num[i]+num[p]+num[q]>0){
			q--;
		}
		else {
			p++;
		}
		
	}
	i=j;
	}
	return ans;
	} 
int main(){
	vector<int> num;
	//-1 0 1 2 -1 -4
	num.push_back(-1);num.push_back(0);num.push_back(1);num.push_back(2);num.push_back(-1);num.push_back(-4);
	sort(num.begin(),num.end());
	vector<vector<int> > ans=threeSum(num);
	//cout<<ans.size()<<endl;
		for(int i=0;i<ans.size();i++){
			for(int j=0;j<ans[i].size();j++){
				cout<<ans[i][j]<<" ";
			}
			cout<<endl;
		}
	return 1;
}
