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
		//�ҵ��ظ��� 
		while(j<S.size()&&S[i]==S[j]) j++;
		int size=ans.size();//��һ�δ���õ�ansԪ�ظ��� 
		//�����ظ��ģ�û���ظ�Ԫ�أ�len=1 �ܹ���j-i��Ԫ��Ҫ���� 
		for(int len=1;len<=j-i;len++) {
			
			for(int k=0;k<size;k++){
				//�ҵ��ϴδ���õĽ����ÿ�����϶�Ҫ���� 
				vector<int> temp(ans[k]);
				//����S[i],���ϴν�������м��ϣ������ظ���len��S[i] 
				for(int m=0;m<len;m++) temp.push_back(S[i]);
				ans.push_back(temp);
			}
			
		}
		//�´δ�j��ʼ 
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
