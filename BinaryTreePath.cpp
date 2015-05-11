#include<stdio.h>
#include<vector>
#include<iostream>
#include <algorithm>
using namespace std;
 void print_(const int & i)
      {
               cout<<i<<endl;
       }
       
int main(){
	//pop_back并不真正从vector中移走元素，而只是调整了size的大小和迭代器的位置
	vector<int> s;
	for(int i=0;i<=5;i++)
	s.push_back(i);
	cout<<"First time,output of for_each:"<<endl;
    for_each(s.begin(),s.end(),print_);
	
	cout<<"从begin,到end-1"<<endl;
	for(vector<int>::iterator iter=s.begin();iter!=s.end();iter++){
		cout<<*iter<<endl;
	}
	cout<<"size:"<<s.size()<<endl;
	cout<<"gg"<<endl;
	s.pop_back();
	s.pop_back();
	//s.pop_back();
	cout<<"size:"<<s.size()<<endl;
	for(int i=s.size()-1;i>=0;i--){
		cout<<s[i]<<endl;
	}
	cout<<"pop_back() 迭代输出："<<endl;
	for(vector<int>::iterator iter=s.begin();iter!=s.end();iter++){
		cout<<*iter<<endl;
	}
	cout<<"逆序"<<endl;
	
	//范围从[begin.....................end-1] 
	for(vector<int>::iterator iter=s.end()-1;iter>=s.begin();iter--){
		cout<<*iter<<endl;
	}
	cout<<"最后两个元素并没有真正删除："<<endl; 
	vector<int>::iterator iter=s.end();
	//pop_back()并不是删除vector中元素，只是改变size,迭代器的位置 
	cout<<*(iter++)<<endl;
	cout<<*(iter++)<<endl;
	return 1;
}
