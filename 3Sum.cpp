#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int> > threeSum(vector<int> &num) {
	vector<vector<int> > ans;
	for(int i=0;i<num.size()&&num[i]<=0;){
		int j=i;
		while(j<num.size()&&num[j]==num[i]) j++;
		int target=-1*num[i];
	/*	int left=i+1;
		int right=num.size()-1;
		while(left<right){
			if(num[left]+num[right]==target){
				vector<int> temp;
				temp.push_back(num[i]);
				temp.push_back(num[left]);
				temp.push_back(num[right]);
				ans.push_back(temp);
			}
			
		}*/
		for(int k=i+1;k<num.size()-1;k++){
			for(int m=k+1;m<num.size();m++){
				if(num[k]+num[m]==target){
				vector<int> temp;
				temp.push_back(num[i]);
				temp.push_back(num[k]);
				temp.push_back(num[m]);
				ans.push_back(temp);
				}
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
