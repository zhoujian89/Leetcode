#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
string minWindow(string S, string T) {
	if(S.empty()||S.size()<T.size()) return "";
	const int ASCII=256;
	int expected_count[ASCII];//target�����ַ����ֵĸ���
	int appeared_count[ASCII];//��ǰ�����У��ַ����ֵĴ���
	fill(expected_count,expected_count+ASCII,0);
	fill(appeared_count,appeared_count+ASCII,0);
	int appeared=0,start=0; 
	int startindex=0,width=INT_MAX;
	//hash map target��expected_count
	for(int i=0;i<T.size();i++) expected_count[T[i]]++; 
	for(int end=0;end<S.size();end++){
		//���ַ�����
		if(expected_count[S[end]]>0){
			appeared_count[S[end]]++;
			if(appeared_count[S[end]]<=expected_count[S[end]]){
			appeared++;
			//cout<<"appeared"<<endl; 
				}
		}
		if(appeared==T.size()){
			//startҪ�ƶ���һ����S[end]=S[start]��appeared_count[S[start]]>expected_count[S[start]] 
			//��expected_count[S[start]]==0 
   //while��ֹʱ��expected_count[S[start]]==1&&appeared_count[S[start]]<=expected_count[S[start]] 
		 while(expected_count[S[start]]==0||appeared_count[S[start]]>expected_count[S[start]]){
		 	appeared_count[S[start]]--;
		 	start++;
		 }	
		 	if(width>end-start+1){
		 		width=end-start+1;
		 		startindex=start;
		 	} 
		 
		}
	}
	return S.substr(startindex,width);

}
int main(){
    string S = "ADOBECODEBANCABC";
    string T = "ABC";
	cout<<minWindow(S,T)<<endl;
	return 1;
} 

