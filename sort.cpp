#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
int main(){
	vector<int> v;
	v.push_back(1);
	v.push_back(5);
	v.push_back(3);
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++)
	cout<<v[i]<<"  ";
	cout<<endl;
	return 1;
}
