#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
class _print{
	public:
	void operator()(int &a){
	cout<<a<<endl;	
	}
}; 
 void print_(const int & i)
      {
               cout<<i<<endl;
       }
       
int main(){
	vector<int> s;
	for(int i=0;i<=5;i++)
	s.push_back(i);
	cout<<"传递函数指针："<<endl;
	for_each(s.begin(),s.end(),print_);
	cout<<"传递函数对象："<<endl;
	for_each(s.begin(),s.end(),_print());
	return 1;
	} 
