#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
string minWindow(string S, string T) {
	if(S.empty()||S.size()<T.size()) return "";
	const int ASCII=256;
	int expected_count[ASCII];//target串中字符出现的个数
	int appeared_count[ASCII];//当前窗口中，字符出现的次数
	fill(expected_count,expected_count+ASCII,0);
	fill(appeared_count,appeared_count+ASCII,0);
	int appeared=0,start=0; 
	int startindex=0,width=INT_MAX;
	//hash map target到expected_count
	for(int i=0;i<T.size();i++) expected_count[T[i]]++; 
	for(int end=0;end<S.size();end++){
		//该字符出现
		if(expected_count[S[end]]>0){
			appeared_count[S[end]]++;
			if(appeared_count[S[end]]<=expected_count[S[end]]){
			appeared++;
			//cout<<"appeared"<<endl; 
				}
		}
		if(appeared==T.size()){
			//start要移动，一定是S[end]=S[start]且appeared_count[S[start]]>expected_count[S[start]] 
			//或expected_count[S[start]]==0 
   //while终止时，expected_count[S[start]]==1&&appeared_count[S[start]]<=expected_count[S[start]] 
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

