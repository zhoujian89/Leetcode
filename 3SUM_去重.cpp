#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int> > threeSum(vector<int> &num) {
	vector<vector<int> > ans;
	//�ȹ̶�һ��Ԫ��num[i],Ȼ��������ָ�룬����num[i]+num[p]+num[q]=0���� 
	for(int i=0;i<num.size()&&num[i]<=0;){
	int j=i;
	//��֤û���ظ���num[i] 
	while(j<num.size()&&num[j]==num[i]) j++;
	int p=i+1;
	int q=num.size()-1;
	//����������������Ԫ�� 
	while(p<q){
		//�ҵ�����0 
		if(num[i]+num[p]+num[q]==0){
			vector<int> temp;
			temp.push_back(num[i]);
			temp.push_back(num[p]);
			temp.push_back(num[q]);
			ans.push_back(temp);
			//��p,qȥ��
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
