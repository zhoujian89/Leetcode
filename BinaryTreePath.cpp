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
	//pop_back����������vector������Ԫ�أ���ֻ�ǵ�����size�Ĵ�С�͵�������λ��
	vector<int> s;
	for(int i=0;i<=5;i++)
	s.push_back(i);
	cout<<"First time,output of for_each:"<<endl;
    for_each(s.begin(),s.end(),print_);
	
	cout<<"��begin,��end-1"<<endl;
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
	cout<<"pop_back() ���������"<<endl;
	for(vector<int>::iterator iter=s.begin();iter!=s.end();iter++){
		cout<<*iter<<endl;
	}
	cout<<"����"<<endl;
	
	//��Χ��[begin.....................end-1] 
	for(vector<int>::iterator iter=s.end()-1;iter>=s.begin();iter--){
		cout<<*iter<<endl;
	}
	cout<<"�������Ԫ�ز�û������ɾ����"<<endl; 
	vector<int>::iterator iter=s.end();
	//pop_back()������ɾ��vector��Ԫ�أ�ֻ�Ǹı�size,��������λ�� 
	cout<<*(iter++)<<endl;
	cout<<*(iter++)<<endl;
	return 1;
}
