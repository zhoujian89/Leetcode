#include<iostream>
#include<map>
using namespace std;
/*leetcode map µœ÷*/
int main(){
	int A[]={1,1,2,2,3,3,3,4,4};
	int n=8;
	int max=0;
	map<int ,int> m;
	map <int ,int >::iterator iter; 
	for(int i=0;i<n;i++){
		iter=m.find(A[i]);
		if(iter==m.end()){
			m.insert(map <int,int>::value_type(A[i],1));
		}
		else iter->second++;
	}
	for(iter=m.begin();iter!=m.end();iter++){
		if(iter->second>max){
			max=iter->second;
		}
	}
	cout<<"max: "<<max<<endl;
	m.clear();
	return 1;
}
