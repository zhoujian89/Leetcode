#include<iostream>
#include<math.h>
#include<stack>
#include<vector>
using namespace std;
vector<int> plusone(vector<int> & d){
//	vector<int> result;
	int flag=0; 
	for(int i=d.size()-1;i>=0;i--){
		if(i==d.size()-1){ 
		if(d[i]+1<=9) d[i]=d[i]+1;
		else {
			d[i]=0;
			flag=1;
		}
		}
		else {
		if(d[i]+flag<=9) {
		d[i]=d[i]+flag;
		flag=0;
		}
		else {
			d[i]=0;
			flag=1;	
		}
			}
		
		
	} 
	if(d[0]==0&&flag==1){
		d.insert(d.begin(),1);
	}
	return d;
/*	vector<int> result;
	int p=0;
	int num=0;
	stack<int> s;
	for(int i=0;i<d.size();i++){
		num=num+d[i]*pow(10,d.size()-i-1);
	}
	cout<<num<<endl;
	num++;
	while(num!=0){
		p=num%10;
		s.push(p);
		num=num/10;	
	}
	while(!s.empty()){
		result.push_back(s.top());
		s.pop();
			}
			return result;
*/	
}
int main(){
	vector<int> result;//[9,8,7,6,5,4,3,2,1,0]
	vector<int> d;
	d.push_back(9);
	d.push_back(8);
	d.push_back(9);
	d.push_back(9);
	d.push_back(9);
//	d.push_back(4);
//	d.push_back(3);
//	d.push_back(2);
//	d.push_back(1);
	//d.push_back(0);
	result=plusone(d);
	for(int i=0;i<result.size();i++){
		cout<<result[i];
	}
} 
