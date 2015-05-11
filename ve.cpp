#include<string> 
#include<cstring>
#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;
vector<double>* f(){
	vector<double> v1;
	vector<double> v2;
	vector<double> v3;
	vector<double> * v=new vector<double>[3];
	v1.push_back(1.0);
	v2.push_back(1.0);
	v3.push_back(1.0);
	v1.push_back(1.0);
	v2.push_back(1.0);
	v3.push_back(1.0);
	v1.push_back(1.0);
	v2.push_back(1.0);
	v3.push_back(1.0);
	v[0]=v1;
	v[1]=v2;
	v[2]=v3;
	return v;
	
}
int main(){
	vector<double> * v=f();
	cout<<v[0].size()<<endl;
	cout<<v[1].size()<<endl;
	cout<<v[2].size()<<endl;
	//vector<Point>().swap(pointVec);
//	cout << "Vector 的 容量为" << v.capacity() << endl; 
	for(int i=0;i<3;i++)
	vector<double>().swap(v[i]);
//	 cout << "Vector 的 容量为" << v.capacity() << endl; 
	
} 
